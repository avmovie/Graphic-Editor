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
#include <QTextCodec>
#include <QString>
#include <QTextCursor>
#include <QToolBar>
#include <QComboBox>
#include <QFontComboBox>
#include <QColorDialog>
#include <QTextListFormat>
#include <QFontDatabase>
#include <QPrintDialog>
#include <QPrinter>
#include <QPrintPreviewDialog>
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
    void createToolBars();
    void createStatus();

    QMdiArea *mdiArea;
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exportAction;
    QAction *printAction;
    QAction *printViewAction;
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

    QToolBar *fileToolBar;				//font attributes tool bar
    QToolBar *editToolBar;				// font edit attributes tool bar
    QToolBar *formatToolBar;			//font format attributes tool bar
    QToolBar *comboToolBar;				//font combox tool bar
    QComboBox *comboStyle;
    QFontComboBox *combo;
    QComboBox *comboSize;				//font size combox
    QFontComboBox *comboFont;			//chose font family

    void fileNew();
    void windowTitle();
    void enableTextEdit();
    void updateMenus();
    SubTextEdit *createTextEditor();
    SubTextEdit *activeTextEditor();

    void fileOpen();
    QMdiSubWindow *findOpenedFile(const QString &filename);	//check opened file whether was already opend in editor
    void fileLoad(const QString &FullFileName);

    void fileSave();
    void fileSaveAs();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void selectAll();
    void listStyle(int i);
    void textColor();
    void textFamily(const QString &f);
    void textSize(const QString &p);
    void textBold();
    void textItalic();
    void textUnderline();
    void textAlign(QAction *a);
    void filePrint();
    void filePrintView();
    void printPreview(QPrinter *);
};

#endif // MAINWINDOW_H
