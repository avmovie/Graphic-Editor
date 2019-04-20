#include "subtextedit.h"

SubTextEdit::SubTextEdit()
{
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;
}

void SubTextEdit::newFile()
{
    static  int subSequenceNumber = 1;
    isUntitled = true;
    //curfile retains current temporary filename
    curFileName= tr("Document %1").arg(subSequenceNumber++);
    //setwindowtitle
    this->setWindowTitle(curFileName+"-Geditor");
}

QString SubTextEdit::currentFileName()
{
    return curFileName;
}

void SubTextEdit::closeEvent(QCloseEvent *event)
{
    event->accept();
}

QString SubTextEdit::currentFilePath()
{
    return curFilePath;
}

void SubTextEdit::documentWasModified()
{
    this->setWindowModified(document()->isModified());
}

