#include "subtextedit.h"
#include <QtWidgets>

SubTextEdit::SubTextEdit()
{
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;
}

void SubTextEdit::newFile()
{
    static  int subSequenceNumber = 1;
    isUntitled = true;
    curFileName= tr("Document %1").arg(subSequenceNumber++);
    this->setWindowTitle(curFileName+"[*]"+"-Geditor");
    connect(document(),&QTextDocument::contentsChanged,this,&SubTextEdit::documentWasModified);
}

QString SubTextEdit::currentFileName()
{
    return strippedName(curFullFileName);
}

void SubTextEdit::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void SubTextEdit::documentWasModified()
{
    this->setWindowModified(document()->isModified());
}

QString SubTextEdit::strippedName(const QString &fullfilename)
{
    return  QFileInfo(fullfilename).fileName();
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

        }
    }
}
