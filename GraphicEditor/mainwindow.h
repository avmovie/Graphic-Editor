#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QMdiArea>
#include <QAction>
#include <QActionGroup>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QFileDialog>
#include "subtextedit.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void createActions();
    void createMenus();

    QMdiArea *mdiArea;
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exportAction;
    QAction *printAction;
    QAction *closeAction;
    QAction *exitAction;

    QAction *undoAction;
    QAction *redoAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *selectAllAction;

    QAction *boldTextAction;
    QAction *italicTextAction;
    QAction *underlineTextAction;

    QAction *alignLeftAction;
    QAction *alignRightAction;
    QAction *alignCenterAction;
    QAction *alignJustifyAction;
    QAction *codeAction;
    QAction *colorAction;

    QAction *styleTitleAction;
    QAction *styleSubTitleAction;
    QAction *styleBodyAction;
    QAction *styleHeading1Action;
    QAction *styleHeading2Action;
    QAction *styleHeading3Action;
    QAction *styleModifier;

    QAction *listDisc;
    QAction *listCircle;
    QAction *listSquare;
    QAction *listDecimal;
    QAction *listLowerAlpha;
    QAction *listUpperAlpha;
    QAction *listUpperRoman;
    QAction *listLowerRoman;

    QAction *insertImageAction;
    QAction *insertTableAction;
    QAction *insertCurDateAction;

    QAction *textAction;
    QAction *alignAction;

    QAction *aboutQtAction;

    QActionGroup *groupTextFormat;
    QActionGroup *groupTextStyle;
    QActionGroup *groupListStyle;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *formatMenu;
    QMenu *insertMenu;
    QMenu *stylesMenu;
    QMenu *toolsMenu;
    QMenu *helpMenu;
    QMenu *textMenu;
    QMenu *alignMenu;


    void fileNew();
    void windowTitle();
    void enableTextEdit();
    void updateMenus();
    SubTextEdit *createTextEditor();
    SubTextEdit *activeTextEditor();

    void fileOpen();
    void fileLoad(const QString &FullFileName);
    void setCurrentFile(const QString &filename);
//    void fileSave();
//    void fileSaveAs();
//    void filePrint();
//    void copy();
//    void paste();
//    void insertImage();
//    void insertTable();
//    void insertDate();
//
//    void textBold(bool);
//    void textItalic(bool);
//    void textUnderline(bool);
//   void textCode(bool);
//
//    void textAlign(QAction *txtalg);
//    void textColor();
//void styleTitle();

};

#endif // MAINWINDOW_H
