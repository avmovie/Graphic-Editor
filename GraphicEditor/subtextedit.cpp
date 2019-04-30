#include "subtextedit.h"
#include <QtWidgets>

SubTextEdit::SubTextEdit()
{
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;
}

void SubTextEdit::newFile()
{
    static int sequence = 1;
    isUntitled = true;
    curFile = tr("Document%1").arg(sequence++);
    setWindowTitle(curFile+"[*]");
    connect(document(),&QTextDocument::contentsChanged,this,&SubTextEdit::documentWasModified);
}

//modify the window title when document was modified
void SubTextEdit::documentWasModified()
{
   setWindowModified(document()->isModified());
}

//get filename from currentfilepath
QString SubTextEdit::strippedName( const QString &fullfilename)
{
   return QFileInfo(fullfilename).fileName();
}

QString SubTextEdit::currentFileBaseName()
{
    return strippedName(curFile);
}

bool SubTextEdit::loadFilie(const QString &filename)
{
   if(filename.isEmpty()==false)
   {
        if(QFile::exists(filename)==false)
        {
            return false;
        }
        QFile file(filename);
        if(file.open(QFile::ReadOnly)==false)
        {
            return false;
        }
        QByteArray data;
        while (file.atEnd()==false)
        {
            data += file.readLine();
        }
        QTextCodec *codec = Qt::codecForHtml(data);
        QString str = codec->toUnicode(data);
        if(Qt::mightBeRichText(str))
        {
            this->setHtml(str);
        }
        else
        {
            str = QString::fromLocal8Bit(data);
            this->setPlainText(str);
        }
   }

   //set current file
   setCurrentFile(filename);
   connect(document(),&QTextDocument::contentsChanged,this,&SubTextEdit::documentWasModified);
   return true;

}

void SubTextEdit::setCurrentFile(const QString &filename)
{
    curFile = QFileInfo(filename).canonicalFilePath();
    //document was entitled
    isUntitled = false ;
    //document was not modified
    document()->setModified(false);
    //set window title and return file name
    setWindowModified(false);
    setWindowTitle(currentFileBaseName()+"[*]");
}

bool SubTextEdit::save()
{
    if(isUntitled)
    {
        return saveAs();
    }
    else {
        return saveFile(curFile);
    }
}

bool SubTextEdit::saveAs()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("save as"),curFile,tr("HTML(*.html *.htm);;All(*.*)")) ;
    if (filename.isEmpty())
    {
        return false;
    }
    return saveFile(filename);
}

bool SubTextEdit::saveFile(QString filename)
{
    if(!(filename.endsWith(".htm",Qt::CaseInsensitive)|| filename.endsWith(".html",Qt::CaseInsensitive)))
    {
        filename += ".html";	//set default html
    }
    QTextDocumentWriter writer(filename);
   bool success = writer.write(this->document());
   if(success)
   {
       setCurrentFile(filename);
   }
   return success;
}

//a message box for save file
bool SubTextEdit::savePromot()
{
    if(!document()->isModified())
    {
        return false;
    }
    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this,tr("Do you want to save your file"),tr("Document'%1'was already modified.Do you want to  save it?")
                               .arg(currentFileBaseName()),QMessageBox::Save | QMessageBox::Discard |QMessageBox::Cancel);
    if(ret == QMessageBox::Save)
        return save();
    else if (ret == QMessageBox::Cancel)
        return false;
    return true;
}

void SubTextEdit::closeEvent(QCloseEvent *event)
{
    if(savePromot())
        event->accept();
    else
    {
        event->ignore();
    }
}

void SubTextEdit::mergeFormatOnwordsOrSelection(const QTextCharFormat &format)
{
    QTextCursor cursor = this->textCursor();
    if(cursor.hasSelection()==false)
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    this->mergeCurrentCharFormat(format);
}

void SubTextEdit::setAlign(int align)
{
    if(align==1)
        this->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
    else if(align==2)
        this->setAlignment(Qt::AlignHCenter);
    else if(align==3)
        this->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
    else if(align==4)
        this->setAlignment(Qt::AlignJustify);
}

void SubTextEdit::setStyle(int style)
{
    QTextCursor cursor = this->textCursor();
    if(style!=0)
    {
        QTextListFormat::Style stylename = QTextListFormat::ListDisc;
        switch (style) {
            default:
        case 1 :
            stylename = QTextListFormat::ListDisc;
            break;
        case 2 :
            stylename = QTextListFormat::ListCircle;
            break;
        case 3 :
            stylename = QTextListFormat::ListSquare;
            break;
        case 4 :
            stylename = QTextListFormat::ListDecimal;
            break;
        case 5 :
            stylename = QTextListFormat::ListLowerAlpha;
            break;
        case 6 :
            stylename = QTextListFormat::ListUpperAlpha;
            break;
        case 7 :
            stylename = QTextListFormat::ListLowerRoman;
            break;
        case 8 :
            stylename = QTextListFormat::ListUpperRoman;
            break;
        }
        cursor.beginEditBlock();
        QTextBlockFormat blockFmt = cursor.blockFormat();
        QTextListFormat listFmt;
        if(cursor.currentList())
        {
            listFmt = cursor.currentList()->format();
        }
        else {
            listFmt.setIndent(blockFmt.indent()+1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }
        listFmt.setStyle(stylename);
        cursor.createList(listFmt);
        cursor.endEditBlock();
    }
    else {
        QTextBlockFormat bfmt;
        bfmt.setObjectIndex(-1);
        cursor.mergeBlockFormat(bfmt);
    }
}
