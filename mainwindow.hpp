/**
 * @file    mainwindow.hpp
 * @brief   header of the mainwindow class
 * @author  Arthus DORIATH (Sorann753)
 * @date    16/05/2021
 * @version 0.3
 */

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QLineEdit>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     *@brief the constructor of the MainWindow class
     *@param parent, a pointer to the parent of MainWindow
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     *@brief the destructor of the MainWindow class
     *@param none
     */
    ~MainWindow();



    /**
     *@brief the fonction that correct the input file
     *@param file_to_input, the file to correct
     *@param directory_to_output, the directory where the corected file will be send
     *@return an exit code
     */
    char correctFile(QString file_to_open, QString directory_to_output);



private slots:

    /**
     *@brief start corecting the file when the launchButton is clicked
     *@param none
     *@return void
     */
    void on_launchButton_clicked();

    /**
     *@brief close the program when quit button is clicked
     *@param none
     *@return void
     */
    void on_quitButton_clicked();

    /**
     *@brief open the file browser when the browseFileInput Button is clicked
     *@param none
     *@return void
     */
    void on_browseFileInput_clicked();

    /**
     *@brief open the file browser when the browseFileOutput Button is clicked
     *@param none
     *@return void
     */
    void on_browseFileOutput_clicked();

    /**
     *@brief set newText as the value of inputFile when the text in lineEditInputFile is changed
     *@param newText, a QString containing the new value of text
     *@return void
     */
    void on_lineEditInputFile_textChanged(const QString &newText);

    /**
     *@brief set newText as the value of outputDir when the text in lineEditOutputFile is changed
     *@param newText, a QString containing the new value of text
     *@return void
     */
    void on_lineEditOutputFile_textChanged(const QString &newText);



private:
    Ui::MainWindow *ui;
    QString inputFile;  /* a QString containing the input file's path */
    QString outputDir;  /* a QString containing the output directory's path */

};

#endif // MAINWINDOW_HPP
