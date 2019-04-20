#ifndef SUBTEXTEDIT_H
#define SUBTEXTEDIT_H
#include <QTextEdit>
#include <QWidget>
#include <QCloseEvent>
#include <QTextDocument>
#include <QFileInfo>

class SubTextEdit : public QTextEdit
{
public:
    SubTextEdit();

    void newFile();
    //return current filename
    QString currentFileName();
    //return current file path
    QString currentFilePath();
protected:
   void closeEvent(QCloseEvent *event);
private:
    //statusbar will update status
    void documentWasModified();
    void setCurFileName(QString &filename);
    QString strippedName(const QString &fullFileName) ;
   //curFile retains current filename which was not saved

     // current file path
    QString curFileName;
    QString curFilePath;
    bool isUntitled;
};

#endif // SUBTEXTEDIT_H
