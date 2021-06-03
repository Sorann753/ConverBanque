/**
 * @file    mainwindow.cpp
 * @brief   source code of the mainwindow class
 * @author  Arthus DORIATH (Sorann753)
 * @date    16/05/2021
 * @version 0.3
 */

#include "mainwindow.hpp"
#include "ui_mainwindow.h"



/**
 *@brief the constructor of the MainWindow class
 *@param parent, a pointer to the parent of MainWindow
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



/**
 *@brief the destructor of the MainWindow class
 *@param none
 */
MainWindow::~MainWindow()
{
    delete ui;
}



/**
 *@brief start corecting the file when the launchButton is clicked
 *@param none
 *@return void
 */
void MainWindow::on_launchButton_clicked(){

    //
}



/**
 *@brief close the program when quit button is clicked
 *@param none
 *@return void
 */
void MainWindow::on_quitButton_clicked(){

    //
}



/**
 *@brief open the file browser when the browseFileInput Button is clicked
 *@param none
 *@return void
 */
void MainWindow::on_browseFileInput_clicked(){

    //
}



/**
 *@brief open the file browser when the browseFileOutput Button is clicked
 *@param none
 *@return void
 */
void MainWindow::on_browseFileOutput_clicked(){

    //
}



/**
 *@brief set newText as the value of inputFile when the text in lineEditInputFile is changed
 *@param newText, a QString containing the new value of text
 *@return void
 */
void MainWindow::on_lineEditInputFile_textChanged(const QString &newText){

    //
}



/**
 *@brief set newText as the value of outputDir when the text in lineEditOutputFile is changed
 *@param newText, a QString containing the new value of text
 *@return void
 */
void MainWindow::on_lineEditOutputFile_textChanged(const QString &newText){

    //
}



/**
 *@brief the fonction that correct the input file
 *@param file_to_input, the file to correct
 *@param directory_to_output, the directory where the corected file will be send
 *@return an exit code
 */
char MainWindow::correctFile(QString file_to_open, const QString &directory_to_output){

    //
}
