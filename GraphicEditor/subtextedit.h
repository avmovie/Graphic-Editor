#ifndef SUBTEXTEDIT_H
#define SUBTEXTEDIT_H
#include <QTextEdit>
#include <QWidget>
#include <QCloseEvent>
#include <QTextDocument>
#include <QFileInfo>
#include <QFileDialog>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QTextListFormat>
#include <QPrinter>

class SubTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    SubTextEdit();
    void newFile();
    QString currentFile(){return curFile;}				//get current file name
    bool loadFilie(const QString &filename); 			//load file from computer
    bool save();
    bool saveAs();
    bool saveFile(QString filename);
    void mergeFormatOnwordsOrSelection(const QTextCharFormat &format);
    void setAlign(int align);
    void setStyle(int style);

protected:
   void closeEvent(QCloseEvent *event);

private:
    void documentWasModified();							//modify subwindow title when file was modified
    void readFile(const QString &filename); 			//read file
    void setCurrentFile(const QString &filename);
    QString strippedName(const QString &fullFileName) ;	//get filename from fullfilepath
    QString currentFileBaseName();						//get file base for subwindow
    bool savePromot();
    bool isUntitled;									//if file was entitled
    QString curFile;									//current file path
};

#endif // SUBTEXTEDIT_H
