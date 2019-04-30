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
    createActions();
    createMenus();
    createToolBars();
    connect(mdiArea,&QMdiArea::subWindowActivated,this,&MainWindow::updateMenus);
    updateMenus();
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
    connect(saveAction,&QAction::triggered,this,&MainWindow::fileSave);

   saveAsAction = new QAction(tr("save as"));
   saveAsAction->setIcon(QIcon(":/saveAs.png"));
   saveAsAction->setShortcut(QKeySequence::SaveAs);
   saveAsAction->setToolTip(tr("save file as"));
   saveAsAction->setStatusTip(tr("save file as"));
   connect(saveAsAction,&QAction::triggered,this,&MainWindow::fileSaveAs);

   printAction = new QAction(tr("&print"));
   printAction->setIcon(QIcon(":/print.png"));
   printAction->setShortcut(QKeySequence::Print);
   printAction->setToolTip(tr("print document"));
   printAction->setStatusTip(tr("print document"));
   connect(printAction,&QAction::triggered,this,&MainWindow::filePrint);
   printViewAction = new QAction(tr("print view"),this);
   printViewAction->setStatusTip(tr("print view"));
   connect(printViewAction,&QAction::triggered,this,&MainWindow::filePrintView);


   exportAction = new QAction(tr("&export"));
   exportAction->setIcon(QIcon(":/export.png"));
   exportAction->setShortcut(QKeySequence::Print);
   exportAction->setToolTip(tr("export document"));
   exportAction->setStatusTip(tr("export document"));
   //connect(exportAction,&QAction::triggered,this,&MainWindow::export);

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
   connect(undoAction,&QAction::triggered,this,&MainWindow::undo);



   redoAction = new QAction(tr("&redo"));
   redoAction->setIcon(QIcon(":/redo.png"));
   redoAction->setShortcut(QKeySequence::Redo);
   redoAction->setToolTip(tr("redo former action"));
   redoAction->setStatusTip(tr("redo former action"));
   connect(redoAction,&QAction::triggered,this,&MainWindow::redo);

   cutAction = new QAction(tr("cut"));
   cutAction->setIcon(QIcon(":/cut.png"));
   cutAction ->setShortcut(QKeySequence::Cut);
   cutAction->setToolTip(tr("cut text"));
   cutAction->setStatusTip(tr("cut text"));
   connect(cutAction,&QAction::triggered,this,&MainWindow::cut);

   copyAction= new QAction(tr("copy"));
   copyAction->setIcon(QIcon(":/copy.png"));
   copyAction->setShortcut(QKeySequence::Copy);
   copyAction->setToolTip(tr("copy text"));
   copyAction->setStatusTip(tr("copy text"));
   connect(copyAction,&QAction::triggered,this,&MainWindow::copy);

   pasteAction= new QAction(tr("paste text"));
   pasteAction->setIcon(QIcon(":/paste.png"));
   pasteAction->setShortcut(QKeySequence::Paste);
   pasteAction->setToolTip(tr("paste text"));
   pasteAction->setStatusTip(tr("paste text"));
   connect(pasteAction,&QAction::triggered,this,&MainWindow::paste);

   selectAllAction= new QAction(tr("select All"));
   selectAllAction->setIcon(QIcon(":/selectAll.png"));
   selectAllAction->setShortcut(QKeySequence::SelectAll);
   selectAllAction->setToolTip(tr("selectAll text"));
   selectAllAction->setStatusTip(tr("selectAll text"));
   connect(selectAllAction,&QAction::triggered,this,&MainWindow::selectAll);

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
    connect(boldTextAction,&QAction::trigger,this,&MainWindow::textBold);

    italicTextAction = new QAction(tr("italic"));
    italicTextAction->setShortcut(QKeySequence::Italic);
    italicTextAction->setIcon(QIcon(":/italic.png"));
    italicTextAction->setCheckable(true);
    italicTextAction->setToolTip(tr("italic font"));
    italicTextAction->setStatusTip("font italic");
    connect(italicTextAction,&QAction::triggered,this,&MainWindow::textItalic);

    underlineTextAction = new QAction(tr("underline"));
    underlineTextAction->setShortcut(QKeySequence::Underline);
    underlineTextAction->setIcon(QIcon(":/underline.png"));
    underlineTextAction->setCheckable(true);
    underlineTextAction->setToolTip(tr("underline font"));
    underlineTextAction->setStatusTip("font underline");
    connect(underlineTextAction,&QAction::triggered,this,&MainWindow::textUnderline);

    groupTextFormat = new QActionGroup(this);
    connect(groupTextFormat,&QActionGroup::triggered,this,&MainWindow::textAlign);
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
   connect(colorAction,&QAction::triggered,this,&MainWindow::textColor);

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

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("new"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);
    fileToolBar->addSeparator();
    fileToolBar->addAction(printAction);

    editToolBar= addToolBar(tr("edit"));
    editToolBar->addAction(redoAction);
    editToolBar->addAction(undoAction);
    editToolBar->addSeparator();
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);

    formatToolBar = addToolBar(tr("format"));
    formatToolBar->addAction(boldTextAction);
    formatToolBar->addAction(underlineTextAction);
    formatToolBar->addAction(italicTextAction);
    formatToolBar->addSeparator();
    formatToolBar->addAction(alignLeftAction);
    formatToolBar->addAction(alignRightAction);
    formatToolBar->addAction(alignCenterAction);
    formatToolBar->addAction(alignJustifyAction);
    formatToolBar->addAction(colorAction);

    comboToolBar = addToolBar(tr("combo chose"));
    comboStyle = new QComboBox();
    comboToolBar->addWidget(comboStyle);
    comboStyle->addItem("standard");
    comboStyle->addItem("Disc(●)");
    comboStyle->addItem("Circle(○)");
    comboStyle->addItem("Square(■)");
    comboStyle->addItem("Decimal(1.2.3.)");
    comboStyle->addItem("LowerAlpha(a.b.)");
    comboStyle->addItem("UpperAlpha(A.B.)");
    comboStyle->addItem("LowerRoman(i.ii.)");
    comboStyle->addItem("UpperRoman(I.II.)");
    comboStyle->setToolTip(tr("set list style"));
    connect(comboStyle, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),this,&MainWindow::listStyle);

    comboFont = new QFontComboBox();
    comboToolBar->addWidget(comboFont);
    comboFont->setStatusTip("change font-family");
    connect(comboFont,static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated),this,&MainWindow::textFamily);
    comboSize = new QComboBox();
    comboToolBar->addWidget(comboSize);
    comboSize->setEditable(true);
    comboSize->setToolTip(tr("change font size"));
    QFontDatabase db;
    foreach (int size,db.standardSizes()) {
        comboSize->addItem(QString::number(size));
    connect(comboSize,static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated),this,&MainWindow::textSize);
    comboSize->setCurrentIndex(comboSize->findText(QString::number(QApplication::font().pointSize())));
    }
}

void MainWindow::createStatus()
{
    statusBar()->showMessage(tr("ready"));
}

void MainWindow::fileNew()
{
    //create a new texteditor-->set mdiarea style with tab
    SubTextEdit *textEditor = createTextEditor();
    mdiArea->setTabsMovable(1);
    mdiArea->setTabsClosable(1);
    textEditor->newFile();
    //after add this texteditor to subwindow,need to show this added texteditor otherwise,this new texteditor will not be shown
    textEditor->show();
    enableTextEdit();
}

//after add texteditor and show it on subwindow,meanwhile need to enable some actions
void MainWindow::enableTextEdit()
{
    insertImageAction->setEnabled(true);
    insertTableAction->setEnabled(true);
    insertCurDateAction->setEnabled(true);
    undoAction->setEnabled(true);
    redoAction->setEnabled(true);
    selectAllAction->setEnabled(true);
    cutAction->setEnabled(true);
    pasteAction->setEnabled(true);
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

//when active different subwindow and subtexteditor,should show different enabled actions
void MainWindow::updateMenus()
{
    //at least one texteditor was created and shown
    bool hasTextEditor =(activeTextEditor()!=0);
    saveAction->setEnabled(hasTextEditor);
    saveAsAction->setEnabled(hasTextEditor);
    printAction->setEnabled(hasTextEditor);
    exportAction->setEnabled(hasTextEditor);
    pasteAction->setEnabled(hasTextEditor);
    //at least has one texteditor was shown and textcursor select some text
    bool hasSelectText = activeTextEditor();
    undoAction->setEnabled(hasSelectText);
    redoAction->setEnabled(hasSelectText);
    cutAction->setEnabled(hasSelectText);
    copyAction->setEnabled(hasSelectText);
    pasteAction->setEnabled(hasSelectText);
    pasteAction->setEnabled(hasSelectText);
    selectAllAction->setEnabled(hasSelectText);
    insertImageAction->setEnabled(hasSelectText);
    insertTableAction->setEnabled(hasSelectText);
    insertCurDateAction->setEnabled(hasSelectText);
    boldTextAction->setEnabled(hasSelectText);
    italicTextAction->setEnabled(hasSelectText);
    underlineTextAction->setEnabled(hasSelectText);
    alignCenterAction->setEnabled(hasSelectText);
    alignLeftAction->setEnabled(hasSelectText);
    alignRightAction->setEnabled(hasSelectText);
    alignJustifyAction->setEnabled(hasSelectText);
    styleTitleAction->setEnabled(hasSelectText);
    styleSubTitleAction->setEnabled(hasSelectText);
    styleBodyAction->setEnabled(hasSelectText);
    styleHeading1Action->setEnabled(hasSelectText);
    styleHeading2Action->setEnabled(hasSelectText);
    styleHeading3Action->setEnabled(hasSelectText);
    codeAction->setEnabled(hasSelectText);

    listDisc->setEnabled(hasSelectText);
    listCircle->setEnabled(hasSelectText);
    listDecimal->setEnabled(hasSelectText);
    listSquare->setEnabled(hasSelectText);
    listLowerAlpha->setEnabled(hasSelectText);
    listLowerRoman->setEnabled(hasSelectText);
    listUpperAlpha->setEnabled(hasSelectText);
    listUpperRoman->setEnabled(hasSelectText);
}

//when focus on different subwindow,get and return relevant subtexteditor
SubTextEdit *MainWindow::activeTextEditor()
{
    if(QMdiSubWindow *activeSubWindow = mdiArea->activeSubWindow())
    {
    return qobject_cast<SubTextEdit *>(activeSubWindow->widget());
    }
    return 0;
}

void MainWindow::fileOpen()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("open"),"../",tr("HTML(*htm *.html);;All(*.*)"));
    //if this file already opend in Graphic editor
    if(filename.isEmpty()==false)
    {
        //there have to be a function to check filename whether was already opend in editor
        QMdiSubWindow *existFile = findOpenedFile(filename);
        if(existFile)
        {
            mdiArea->setActiveSubWindow(existFile);
            return;
        }
        //there have no opened file in editor,then add a new texteditor to subwindow and load it
        SubTextEdit *editor = createTextEditor();
        if(editor->loadFilie(filename))
        {
            statusBar()->showMessage(tr("file was already loaded"));
            editor->show();
        }
        else {
            editor->close();
        }
    }
}

QMdiSubWindow* MainWindow::findOpenedFile(const QString &filename)
{
    //canonicalfilepath meas file's absolute filepath but exclude linkfile
    QString filePath = QFileInfo(filename).canonicalFilePath();
    foreach (QMdiSubWindow *window, mdiArea->subWindowList()) {
        SubTextEdit *textEditor = qobject_cast<SubTextEdit*>(window->widget());
        if(textEditor->currentFile()==filePath)
        {
            return window;
        }
    }
    return 0;
}

SubTextEdit *MainWindow::createTextEditor()
{
    //create a texteditor -->add it to subwindow-->enable copy and cut action-->return a pointer of this new texteditor
    SubTextEdit *textEditor = new SubTextEdit;
    mdiArea->addSubWindow(textEditor);
    connect(textEditor,&SubTextEdit::copyAvailable,cutAction,&QAction::setEnabled);
    connect(textEditor,&SubTextEdit::copyAvailable,copyAction,&QAction::setEnabled);
    return  textEditor;
}

void MainWindow::fileSave()
{
    if(activeTextEditor()&&activeTextEditor()->save())
    {
        statusBar()->showMessage(tr("save successfully"),2000);
    }
}

void MainWindow::fileSaveAs()
{
    if(activeTextEditor()&&activeTextEditor()->saveAs())
    {
        statusBar()->showMessage(tr("saveAs successfully"),2000);
    }
}

void MainWindow::redo()
{
    if(activeTextEditor())
    {
        activeTextEditor()->redo();
    }
}

void MainWindow::undo()
{
    if(activeTextEditor())
    {
        activeTextEditor()->undo();
    }
}


void MainWindow::cut()
{
    if(activeTextEditor())
    {
        activeTextEditor()->cut();
    }
}

void MainWindow::copy()
{
    if(activeTextEditor())
    {
        activeTextEditor()->copy();
    }
}

void MainWindow::paste()
{
    if(activeTextEditor())
    {
        activeTextEditor()->paste();
    }
}

void MainWindow::selectAll()
{
    if(activeTextEditor())
    {
        activeTextEditor()->selectAll();
    }
}

void MainWindow::textColor()
{
    if(activeTextEditor())
    {
        QColor color = QColorDialog::getColor(activeTextEditor()->textColor(),this);
        if(color.isValid()==false)
        {
            return;
        }
        QTextCharFormat fmt;
        fmt.setForeground(color);
        activeTextEditor()->mergeCurrentCharFormat(fmt);
       // colorChanged(color);
    }
}

void MainWindow::listStyle(int i)
{
    if(activeTextEditor())
    {
        activeTextEditor()->setStyle(i);
    }

}

void MainWindow::textBold()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(boldTextAction->isChecked()?QFont::Bold:QFont::Normal);
    if(activeTextEditor())
    {
        activeTextEditor()->mergeFormatOnwordsOrSelection(fmt);
    }
}

void MainWindow::textItalic()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(italicTextAction->isChecked());
    if(activeTextEditor())
    {
        activeTextEditor()->mergeFormatOnwordsOrSelection(fmt);
    }
}

void MainWindow::textUnderline()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(underlineTextAction->isChecked());
    if(activeTextEditor())
    {
        activeTextEditor()->mergeFormatOnwordsOrSelection(fmt);
    }
}

void MainWindow::textFamily(const QString &f)
{
   QTextCharFormat fmt;
   fmt.setFontFamily(f);
}

void MainWindow::textSize(const QString &p)
{
    qreal pointSize = p.toFloat();
    if(p.toFloat()>0)
    {
        QTextCharFormat fmt;
        fmt.setFontPointSize(pointSize);
        if(activeTextEditor())
        {
            activeTextEditor()->mergeFormatOnwordsOrSelection(fmt);
        }
    }
}

void MainWindow::textAlign(QAction *a)
{
    if(a == alignLeftAction)
        activeTextEditor()->setAlign(1);
    else if(a == alignCenterAction)
        activeTextEditor()->setAlign(2);
    else if(a == alignRightAction)
        activeTextEditor()->setAlign(3);
    else if(a == alignJustifyAction)
        activeTextEditor()->setAlign(4);
}

void MainWindow::filePrint()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog *dlg = new QPrintDialog(&printer,this);
    if(activeTextEditor()->textCursor().hasSelection())
    {
        dlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    }
        dlg->setWindowTitle(tr("print document"));
        if(dlg->exec()==QDialog::Accepted)
            activeTextEditor()->print(&printer);
        delete dlg;
}

void MainWindow::filePrintView()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer,this);
    connect(&preview,&QPrintPreviewDialog::paintRequested,this,&MainWindow::printPreview);
    preview.exec();
}

void MainWindow::printPreview(QPrinter * printer)
{
    activeTextEditor()->print(printer);
}
