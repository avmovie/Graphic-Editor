#ifndef SUBTEXTEDIT_H
#define SUBTEXTEDIT_H
#include <QTextEdit>
#include <QWidget>
#include <QCloseEvent>
#include <QTextDocument>
#include <QFileInfo>

class SubTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    SubTextEdit();

    void newFile();
    QString currentFileName();
    QString currentFullFileName();
protected:
   void closeEvent(QCloseEvent *event);
private:
    void documentWasModified();
    void setCurFileName(QString &filename);
    bool loadFilie(const QString &filename);
    void readFile(const QString &filename);
    QString strippedName(const QString &fullFileName) ;
    QString curFileName;
    QString curFullFileName;
    bool isUntitled;
};

#endif // SUBTEXTEDIT_H
