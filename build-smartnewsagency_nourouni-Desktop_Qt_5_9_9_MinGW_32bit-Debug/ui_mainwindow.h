/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_17;
    QLabel *label_3;
    QPushButton *refresh;
    QTextEdit *textEdit;
    QWidget *page_2;
    QTableView *tableView;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QFrame *frame;
    QLabel *label_2;
    QRadioButton *radioButton_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_recherche_publicite;
    QFrame *frame_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_titre;
    QLineEdit *lineEdit_domaine;
    QLineEdit *lineEdit_redacteur;
    QDateEdit *dateEdit;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *label_17;
    QLineEdit *lineEdit_recette;
    QPushButton *pushButton_stat;
    QWidget *page_3;
    QTableView *tableView_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QFrame *frame_3;
    QLabel *label_11;
    QRadioButton *radioButton;
    QFrame *frame_4;
    QLabel *label_12;
    QLabel *label_16;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_21;
    QLabel *label_15;
    QLineEdit *ribcollab;
    QLabel *label_18;
    QLineEdit *lineEdit_12;
    QDateEdit *datecollab;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *lineEdit_13;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(50, 20, 711, 511));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 30, 181, 51));
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(255, 170, 127);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 90, 181, 51));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(255, 170, 127);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        pushButton_17 = new QPushButton(page);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(40, 300, 75, 23));
        pushButton_17->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(144, 134, 120);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(470, 70, 121, 21));
        refresh = new QPushButton(page);
        refresh->setObjectName(QStringLiteral("refresh"));
        refresh->setGeometry(QRect(470, 100, 93, 28));
        textEdit = new QTextEdit(page);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(470, 130, 241, 161));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        tableView = new QTableView(page_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(340, 50, 381, 251));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 470, 75, 23));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(144, 134, 120);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 380, 111, 31));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(170, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(140, 380, 111, 31));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(170, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        frame = new QFrame(page_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(440, 370, 271, 101));
        frame->setStyleSheet(QStringLiteral("background-color:rgb(170, 255, 255);"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(2);
        frame->setMidLineWidth(0);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 10, 211, 21));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_2->setFont(font);
        radioButton_2 = new QRadioButton(frame);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(70, 40, 97, 20));
        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 261, 51));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(470, 0, 131, 20));
        pushButton_recherche_publicite = new QPushButton(page_2);
        pushButton_recherche_publicite->setObjectName(QStringLiteral("pushButton_recherche_publicite"));
        pushButton_recherche_publicite->setGeometry(QRect(354, 0, 101, 23));
        pushButton_recherche_publicite->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(170, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        frame_2 = new QFrame(page_2);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 80, 251, 241));
        frame_2->setStyleSheet(QStringLiteral("background-color:rgb(255, 170,127);"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(2);
        frame_2->setMidLineWidth(0);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 10, 71, 16));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 40, 47, 14));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 70, 71, 16));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 100, 61, 16));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 130, 81, 16));
        lineEdit_id = new QLineEdit(frame_2);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(90, 10, 113, 20));
        lineEdit_titre = new QLineEdit(frame_2);
        lineEdit_titre->setObjectName(QStringLiteral("lineEdit_titre"));
        lineEdit_titre->setGeometry(QRect(90, 40, 113, 20));
        lineEdit_domaine = new QLineEdit(frame_2);
        lineEdit_domaine->setObjectName(QStringLiteral("lineEdit_domaine"));
        lineEdit_domaine->setGeometry(QRect(90, 70, 113, 20));
        lineEdit_redacteur = new QLineEdit(frame_2);
        lineEdit_redacteur->setObjectName(QStringLiteral("lineEdit_redacteur"));
        lineEdit_redacteur->setGeometry(QRect(90, 130, 113, 20));
        dateEdit = new QDateEdit(frame_2);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(90, 100, 110, 22));
        pushButton_ajouter = new QPushButton(frame_2);
        pushButton_ajouter->setObjectName(QStringLiteral("pushButton_ajouter"));
        pushButton_ajouter->setGeometry(QRect(10, 210, 75, 23));
        pushButton_ajouter->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(0, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        pushButton_8 = new QPushButton(frame_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(90, 210, 75, 23));
        pushButton_8->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(0, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        pushButton_9 = new QPushButton(frame_2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(170, 210, 75, 23));
        pushButton_9->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(85, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        label_17 = new QLabel(frame_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 160, 91, 16));
        lineEdit_recette = new QLineEdit(frame_2);
        lineEdit_recette->setObjectName(QStringLiteral("lineEdit_recette"));
        lineEdit_recette->setGeometry(QRect(90, 160, 113, 20));
        pushButton_stat = new QPushButton(page_2);
        pushButton_stat->setObjectName(QStringLiteral("pushButton_stat"));
        pushButton_stat->setGeometry(QRect(290, 380, 111, 31));
        pushButton_stat->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(170, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        tableView_2 = new QTableView(page_3);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(10, 50, 381, 251));
        pushButton_10 = new QPushButton(page_3);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(404, 180, 101, 23));
        pushButton_10->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(101, 190, 155);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        pushButton_12 = new QPushButton(page_3);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(10, 440, 75, 23));
        pushButton_12->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(144, 134, 120);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        pushButton_13 = new QPushButton(page_3);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(10, 310, 111, 31));
        pushButton_13->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(170, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        pushButton_14 = new QPushButton(page_3);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(10, 350, 111, 31));
        pushButton_14->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(170, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 0, 261, 31));
        label_10->setFont(font1);
        lineEdit_6 = new QLineEdit(page_3);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(520, 180, 131, 20));
        frame_3 = new QFrame(page_3);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(430, 50, 221, 121));
        frame_3->setStyleSheet(QStringLiteral("background-color:rgb(170, 255, 255);"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Plain);
        frame_3->setLineWidth(2);
        frame_3->setMidLineWidth(0);
        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 10, 111, 21));
        label_11->setFont(font);
        radioButton = new QRadioButton(frame_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(50, 60, 97, 20));
        frame_4 = new QFrame(page_3);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(410, 220, 251, 291));
        frame_4->setStyleSheet(QStringLiteral("background-color:rgb(255, 170, 127);"));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Plain);
        frame_4->setLineWidth(2);
        frame_4->setMidLineWidth(0);
        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 10, 71, 16));
        label_16 = new QLabel(frame_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 50, 47, 14));
        lineEdit_2 = new QLineEdit(frame_4);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 10, 113, 20));
        lineEdit_10 = new QLineEdit(frame_4);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(90, 50, 113, 20));
        pushButton_15 = new QPushButton(frame_4);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(20, 140, 75, 23));
        pushButton_15->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(170, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        pushButton_16 = new QPushButton(frame_4);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(110, 140, 75, 23));
        pushButton_16->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(170, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        pushButton_21 = new QPushButton(frame_4);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(70, 170, 75, 23));
        pushButton_21->setStyleSheet(QLatin1String("QPushButton {\n"
"padding: 5px;\n"
"border-radius: 5px;\n"
"background-color:rgb(170, 255, 255);\n"
"font-weight: bold;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color :white;\n"
"}"));
        label_15 = new QLabel(frame_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 110, 71, 16));
        ribcollab = new QLineEdit(frame_4);
        ribcollab->setObjectName(QStringLiteral("ribcollab"));
        ribcollab->setGeometry(QRect(90, 110, 111, 20));
        label_18 = new QLabel(frame_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 80, 61, 16));
        lineEdit_12 = new QLineEdit(frame_4);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(90, 80, 113, 20));
        datecollab = new QDateEdit(frame_4);
        datecollab->setObjectName(QStringLiteral("datecollab"));
        datecollab->setGeometry(QRect(110, 210, 110, 22));
        label_19 = new QLabel(frame_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 210, 71, 16));
        label_20 = new QLabel(frame_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(20, 250, 61, 16));
        lineEdit_13 = new QLineEdit(frame_4);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(100, 250, 111, 20));
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Publicit\303\251s", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Collaborations", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Badget", Q_NULLPTR));
        refresh->setText(QApplication::translate("MainWindow", "refresh", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Enregistrer PDF", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Imprimer", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Trier selon :", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffaa7f;\">PUBLICITE</span></p><p><span style=\" color:#ffaa7f;\"><br/></span></p></body></html>", Q_NULLPTR));
        pushButton_recherche_publicite->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "TITRE", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "DOMAINE :", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "DATE", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "REDACTEUR", Q_NULLPTR));
        pushButton_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "RECETTE:", Q_NULLPTR));
        pushButton_stat->setText(QApplication::translate("MainWindow", "statistique", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "Enregistrer PDF", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("MainWindow", "Imprimer", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffaa7f;\">COLLABORATIONS</span></p><p><span style=\" color:#ffaa7f;\"><br/></span></p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Trier selon:", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "NOM", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "RIB", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "DOMAINE", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "DATE", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "CONTACT", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
