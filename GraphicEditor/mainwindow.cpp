#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setViewMode(QMdiArea::TabbedView);
    mdiArea->setDocumentMode(true);
    this->setCentralWidget(mdiArea);
    connect(mdiArea,&QMdiArea::subWindowActivated,this,&MainWindow::updateMenus);
    updateMenus();
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()
{
    newAction = new QAction(tr("&new file"),this);
    newAction->setIcon(QIcon(":/newFile.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setToolTip(tr("new file"));
    newAction->setStatusTip(tr("new file"));
    connect(newAction,&QAction::triggered,this,&MainWindow::fileNew);

    closeAction = new QAction(tr("&close file"),this);
    closeAction->setIcon(QIcon(":/close.png"));
    closeAction->setShortcut(QKeySequence::Close);
    closeAction->setToolTip(tr("close file"));
    closeAction->setStatusTip(tr("close file"));
    //connect(closeAction,&QAction::triggered,this,&MainWindow::fileNew);

    openAction = new QAction(tr("&open file"));
    openAction->setIcon(QIcon(":/open.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("open file"));
    openAction->setToolTip(tr("open file"));
    connect(openAction,&QAction::triggered,this,&MainWindow::fileOpen);

    saveAction = new QAction(tr("save"));
    saveAction->setIcon(QIcon(":/save.png"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setToolTip(tr("save current file"));
    saveAction->setStatusTip(tr("save file"));
    //connect(saveAction,&QAction::triggered,this,&MainWindow::fileSave);

   saveAsAction = new QAction(tr("save as"));
   saveAsAction->setIcon(QIcon(":/saveAs.png"));
   saveAsAction->setShortcut(QKeySequence::SaveAs);
   saveAsAction->setToolTip(tr("save file as"));
   saveAsAction->setStatusTip(tr("save file as"));
   //connect(saveAsAction,&QAction::triggered,this,&MainWindow::fileSaveAs);

   printAction = new QAction(tr("&print"));
   printAction->setIcon(QIcon(":/print.png"));
   printAction->setShortcut(QKeySequence::Print);
   printAction->setToolTip(tr("print document"));
   printAction->setStatusTip(tr("print document"));
   //connect(printAction,&QAction::triggered,this,&MainWindow::printAction);

   exportAction = new QAction(tr("&export"));
   exportAction->setIcon(QIcon(":/export.png"));
   exportAction->setShortcut(QKeySequence::Print);
   exportAction->setToolTip(tr("export document"));
   exportAction->setStatusTip(tr("export document"));
   //connect(exportAction,&QAction::triggered,this,&MainWindow::printAction);

    exitAction = new QAction(tr("&exit"),this);
    exitAction->setIcon(QIcon(":/exit.png"));
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setToolTip(tr("exit file"));
    exitAction->setStatusTip(tr("exit file"));
    //connect(exitAction,&QAction::triggered,this,&MainWindow::fileNew);

   undoAction = new QAction(tr("&undo"));
   undoAction->setIcon(QIcon(":/undo.png"));
   undoAction->setShortcut(QKeySequence::Undo);
   undoAction->setToolTip(tr("undo former action"));
   undoAction->setStatusTip(tr("undo former action"));

   redoAction = new QAction(tr("&redo"));
   redoAction->setIcon(QIcon(":/redo.png"));
   redoAction->setShortcut(QKeySequence::Redo);
   redoAction->setToolTip(tr("redo former action"));
   redoAction->setStatusTip(tr("redo former action"));

   cutAction = new QAction(tr("cut"));
   cutAction->setIcon(QIcon(":/cut.png"));
   cutAction ->setShortcut(QKeySequence::Cut);
   cutAction->setToolTip(tr("cut text"));
   cutAction->setStatusTip(tr("cut text"));

   copyAction= new QAction(tr("copy"));
   copyAction->setIcon(QIcon(":/copy.png"));
   copyAction->setShortcut(QKeySequence::Copy);
   copyAction->setToolTip(tr("copy text"));
   copyAction->setStatusTip(tr("copy text"));
   //connect(copyAction,&QAction::triggered,this,&MainWindow::copy);

   pasteAction= new QAction(tr("paste text"));
   pasteAction->setIcon(QIcon(":/paste.png"));
   pasteAction->setShortcut(QKeySequence::Paste);
   pasteAction->setToolTip(tr("paste text"));
   pasteAction->setStatusTip(tr("paste text"));
   //connect(pasteAction,&QAction::triggered,this,&MainWindow::paste);

   selectAllAction= new QAction(tr("select All"));
   selectAllAction->setIcon(QIcon(":/selectAll.png"));
   selectAllAction->setShortcut(QKeySequence::SelectAll);
   selectAllAction->setToolTip(tr("selectAll text"));
   selectAllAction->setStatusTip(tr("selectAll text"));
   ////connect(selectAllAction,&QAction::triggered,this,&SubTextEdit::selectAll);

   insertImageAction= new QAction(tr("insert image"));
   insertImageAction->setIcon(QIcon(":/picture.png"));
   insertImageAction->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_I);
   insertImageAction->setToolTip(tr("insert Image"));
   insertImageAction->setStatusTip(tr("insert Image"));
   //connect(insertImageAction,&QAction::triggered,this,&MainWindow::insertImage);

   insertTableAction= new QAction(tr("insertTable"));
   insertTableAction->setIcon(QIcon(":/table.png"));
   insertTableAction->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_T);
   insertTableAction->setToolTip(tr("insertTable"));
   insertTableAction->setStatusTip(tr("insertTable"));
   //connect(insertTableAction,&QAction::triggered,this,&MainWindow::insertTable);

   insertCurDateAction= new QAction(tr("insert Current Date"));
   insertCurDateAction->setIcon(QIcon(":/date.png"));
   insertCurDateAction->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_D);
   insertCurDateAction->setToolTip(tr("insert current date"));
   insertCurDateAction->setStatusTip(tr("insert current date"));
   //connect(insertCurDateAction,&QAction::triggered,this,&MainWindow::insertDate);

   //choose font style
    boldTextAction = new QAction(tr("bold"));
    boldTextAction->setCheckable(true);
    boldTextAction->setIcon(QIcon(":/bold.png"));
    boldTextAction->setShortcut(QKeySequence::Bold);
    boldTextAction->setToolTip(tr("bold font"));
    boldTextAction->setStatusTip(tr("bold font"));
    //connect(boldTextAction,&QAction::trigger,this,&MainWindow::textBold);

    italicTextAction = new QAction(tr("italic"));
    italicTextAction->setShortcut(QKeySequence::Italic);
    italicTextAction->setIcon(QIcon(":/italic.png"));
    italicTextAction->setCheckable(true);
    italicTextAction->setToolTip(tr("italic font"));
    italicTextAction->setStatusTip("font italic");
    //connect(italicTextAction,&QAction::triggered,this,&MainWindow::italicTextAction);

    underlineTextAction = new QAction(tr("underline"));
    underlineTextAction->setShortcut(QKeySequence::Underline);
    underlineTextAction->setIcon(QIcon(":/underline.png"));
    underlineTextAction->setCheckable(true);
    underlineTextAction->setToolTip(tr("underline font"));
    underlineTextAction->setStatusTip("font underline");
    //connect(underlineTextAction,&QAction::triggered,this,&MainWindow::underlineTextAction);

    groupTextFormat = new QActionGroup(this);
    //connect(groupTextFormat,&QActionGroup::triggered,this,&MainWindow::textAlign);
    if(QApplication::isLeftToRight())
    {
    alignLeftAction = new QAction(tr("left"),groupTextFormat);
    alignLeftAction->setShortcut(Qt::AlignLeft);
    alignLeftAction->setIcon(QIcon(":/left-indent.png"));
    alignLeftAction->setCheckable(true);
    alignLeftAction->setToolTip(tr("left alignment format"));
    alignLeftAction->setStatusTip("left alignment format");

    alignRightAction = new QAction(tr("right"),groupTextFormat);
    alignRightAction->setShortcut(Qt::AlignRight);
    alignRightAction->setIcon(QIcon(":/right-indent.png"));
    alignRightAction->setCheckable(true);
    alignRightAction->setToolTip(tr("right alignment format"));
    alignRightAction->setStatusTip("right alignment format");

    alignCenterAction = new QAction(tr("center"),groupTextFormat);
    alignCenterAction->setShortcut(Qt::AlignCenter);
    alignCenterAction->setIcon(QIcon(":/center-alignment.png"));
    alignCenterAction->setCheckable(true);
    alignCenterAction->setToolTip(tr("center alignment format"));
    alignCenterAction->setStatusTip("center alignment format");

    alignJustifyAction = new QAction(tr("justified"),groupTextFormat);
    alignJustifyAction->setShortcut(Qt::AlignJustify);
    alignJustifyAction->setIcon(QIcon(":/justify-align.png"));
    alignJustifyAction->setCheckable(true);
    alignJustifyAction->setToolTip(tr("justify alignment format"));
    alignJustifyAction->setStatusTip("justify alignment format");
    }

    codeAction = new QAction(tr("code"));
    codeAction->setIcon(QIcon(":/code.png"));
    codeAction->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_C);
    codeAction->setToolTip(tr("code format"));
    codeAction->setStatusTip(tr("code format"));
    //connect(codeAction,&QAction::triggered,this,&MainWindow::textCode);

   colorAction = new QAction(tr("color"));
   colorAction->setIcon(QIcon(":/color.png"));
   colorAction->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_C);
   colorAction->setToolTip(tr("regulate color"));
   colorAction->setStatusTip(tr("regulate color"));
   //connect(colorAction,&QAction::triggered,this,&MainWindow::textColor);

   groupTextStyle = new QActionGroup(this);

    if(QApplication::isLeftToRight())
    {
   styleTitleAction = new QAction(tr("titile"),groupTextStyle);
   styleTitleAction->setCheckable(true);
   styleTitleAction->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_9);
   styleTitleAction->setToolTip(tr("set title style"));
   styleTitleAction->setStatusTip(tr("set title style"));
//   connect(styleTitleAction,&QAction::triggered,this,&MainWindow::styleTitle);

   styleSubTitleAction = new QAction(tr("subtitile"),groupTextStyle);
   styleSubTitleAction->setCheckable(true);
   styleSubTitleAction->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_8);
   styleSubTitleAction->setToolTip(tr("set subtitle style"));
   styleSubTitleAction->setStatusTip(tr("set subtitle style"));
//   connect(styleSubTitleAction,&QAction::triggered,this,&MainWindow::styleSubTitle);

   styleHeading1Action = new QAction(tr("heading1"),groupTextStyle);
   styleHeading1Action->setCheckable(true);
   styleHeading1Action->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_1);
   styleHeading1Action->setToolTip(tr("set heading1 style"));
   styleHeading1Action->setStatusTip(tr("set heading1 style"));
//   connect(styleHeading1Action,&QAction::triggered,this,&MainWindow::styleHeading1);

   styleHeading2Action = new QAction(tr("heading2"),groupTextStyle);
   styleHeading2Action->setCheckable(true);
   styleHeading2Action->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_2);
   styleHeading2Action->setToolTip(tr("set heading2 style"));
   styleHeading2Action->setStatusTip(tr("set heading2 style"));
//   connect(styleHeading2Action,&QAction::triggered,this,&MainWindow::styleHeading2);

   styleHeading3Action = new QAction(tr("heading3"),groupTextStyle);
   styleHeading3Action->setCheckable(true);
   styleHeading3Action->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_3);
   styleHeading3Action->setToolTip(tr("set heading3 style"));
   styleHeading3Action->setStatusTip(tr("set heading3 style"));
//   connect(styleHeading3Action,&QAction::triggered,this,&MainWindow::styleHeading3);

   styleBodyAction = new QAction(tr("Body"),groupTextStyle);
   styleBodyAction->setCheckable(true);
   styleBodyAction->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_0);
   styleBodyAction->setToolTip(tr("set Body style"));
   styleBodyAction->setStatusTip(tr("set Body style"));
//   connect(styleBodyAction,&QAction::triggered,this,&MainWindow::styleBody);
    }

    groupListStyle = new QActionGroup(this);
    if(QApplication::isLeftToRight())
    {
    listDisc = new QAction(tr("disc list"),groupListStyle );
    listDisc->setCheckable(true);
    listCircle = new QAction(tr("circle list"),groupListStyle );
    listCircle->setCheckable(true);
    listSquare = new QAction(tr("square list"),groupListStyle );
    listSquare->setCheckable(true);
    listDecimal = new QAction(tr(" decimal"),groupListStyle );
    listDecimal->setCheckable(true);
    listLowerAlpha = new QAction(tr("lowerAlpha list"),groupListStyle );
    listLowerAlpha->setCheckable(true);
    listLowerRoman = new QAction(tr("lowerRoman list"),groupListStyle );
    listLowerRoman->setCheckable(true);
    listUpperRoman = new QAction(tr("upperRoman list"),groupListStyle );
    listUpperRoman->setCheckable(true);
    listUpperAlpha = new QAction(tr("upperAlpha list"),groupListStyle );
    listUpperAlpha->setCheckable(true);
    }

    aboutQtAction = new QAction(tr("aboutQt"));
    connect(aboutQtAction,&QAction::triggered,this,&QApplication::aboutQt);
}
void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&file"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(printAction);
    fileMenu->addAction(closeAction);
    fileMenu->addAction(exportAction);
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&edit"));
    editMenu->addAction(undoAction) ;
    editMenu->addAction(redoAction) ;
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(selectAllAction);

    insertMenu = menuBar()->addMenu("&insert");
    insertMenu->addAction(insertImageAction);
    insertMenu->addAction(insertTableAction);
    insertMenu->addAction(insertCurDateAction);


    textMenu = new QMenu(tr("&text format"));
    textMenu->addAction(boldTextAction);
    textMenu->addAction(italicTextAction);
    textMenu->addAction(underlineTextAction);

    alignMenu = new QMenu(tr("&align format"));
    alignMenu->addAction(alignLeftAction);
    alignMenu->addAction(alignRightAction);
    alignMenu->addAction(alignCenterAction);
    alignMenu->addAction(alignJustifyAction);

    formatMenu = menuBar()->addMenu(tr("format"));
    formatMenu->addMenu(textMenu);
    formatMenu->addMenu(alignMenu);
    formatMenu->addAction(codeAction);

    stylesMenu=menuBar()->addMenu(tr("&styles"));
    stylesMenu->addAction(styleTitleAction);
    stylesMenu->addAction(styleSubTitleAction);
    stylesMenu->addAction(styleHeading1Action);
    stylesMenu->addAction(styleHeading2Action);
    stylesMenu->addAction(styleHeading3Action);
    stylesMenu->addAction(styleBodyAction);
    stylesMenu->addSeparator();
    stylesMenu->addAction(listDisc);
    stylesMenu->addAction(listCircle);
    stylesMenu->addAction(listSquare);
    stylesMenu->addAction(listDecimal);
    stylesMenu->addAction(listLowerAlpha);
    stylesMenu->addAction(listUpperAlpha);
    stylesMenu->addAction(listLowerRoman);
    stylesMenu->addAction(listUpperRoman);

    toolsMenu=menuBar()->addMenu(tr("&tools"));
   // toolsMenu->addAction(styleModifier) ;
    helpMenu =menuBar()->addMenu(tr("help"));
    helpMenu->addAction(aboutQtAction);

}

void MainWindow::fileNew()
{
    //open
    SubTextEdit *textEditor = createSubWindow();
    mdiArea->setTabsMovable(1);
    mdiArea->setTabsClosable(1);
    textEditor->newFile();
    textEditor->show();
}

// create a new subwindow and make subtextEdit become subwindow's central widget
SubTextEdit *MainWindow::createSubWindow()
{
    SubTextEdit* textEditor = new SubTextEdit;
    mdiArea->addSubWindow(textEditor);
    connect(textEditor,&SubTextEdit::copyAvailable,cutAction,&QAction::setEnabled);
    connect(textEditor,&SubTextEdit::copyAvailable,copyAction,&QAction::setEnabled);
    return textEditor;
}

void MainWindow::enableTextEdit()
{
    insertImageAction->setEnabled(true);
    insertTableAction->setEnabled(true);
    insertCurDateAction->setEnabled(true);
    boldTextAction->setEnabled(true);
    italicTextAction->setEnabled(true);
    underlineTextAction->setEnabled(true);
    alignLeftAction->setEnabled(true);
    alignRightAction->setEnabled(true);
    alignCenterAction->setEnabled(true);
    alignJustifyAction->setEnabled(true);
    colorAction->setEnabled(true);
    styleTitleAction->setEnabled(true);
    styleSubTitleAction->setEnabled(true);
    styleHeading1Action->setEnabled(true);
    styleHeading2Action->setEnabled(true);
    styleHeading3Action->setEnabled(true);
    styleBodyAction->setEnabled(true);
    listDisc->setEnabled(true);
    listCircle->setEnabled(true);
    listSquare->setEnabled(true);
    listDecimal->setEnabled(true);
    listLowerAlpha->setEnabled(true);
    listLowerRoman->setEnabled(true);
    listUpperAlpha->setEnabled(true);
    listUpperRoman->setEnabled(true);
}

void MainWindow::updateMenus()
{
   // bool hasSubTextEditor =(activeTextEditor()!=0);
}

SubTextEdit *MainWindow::activeTextEditor()
{
   // if(QMdiSubWindow *)
}

void MainWindow::fileOpen()
{

}
