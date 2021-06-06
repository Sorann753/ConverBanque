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

    //set the error icon as not visible
    ui->errorInput->setVisible(false);
    ui->errorOutput->setVisible(false);
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
 *@brief start corecting the file and show error style if something is wrong
 *@param none
 *@return void
 */
void MainWindow::on_launchButton_clicked(){

    char errorCode = correctFile(inputFile, outputDir);

    if(errorCode == -1){ //error from the input file

        ui->inputLabel->setStyleSheet("color: #FF0000");
        ui->outputLabel->setStyleSheet("color: #000000");

        ui->errorInput->setVisible(true);
        ui->errorOutput->setVisible(false);
    }

    else if(errorCode == -2){ //error from the output directory

        ui->inputLabel->setStyleSheet("color: #000000");
        ui->outputLabel->setStyleSheet("color: #FF0000");

        ui->errorInput->setVisible(false);
        ui->errorOutput->setVisible(true);
    }

    else{ //no error

        ui->inputLabel->setStyleSheet("color: #000000");
        ui->outputLabel->setStyleSheet("color: #000000");

        ui->errorInput->setVisible(false);
        ui->errorOutput->setVisible(false);
    }
}



/**
 *@brief close the program when quit button is clicked
 *@param none
 *@return void
 */
void MainWindow::on_quitButton_clicked(){

    close();
}



/**
 *@brief open the file browser when the browseFileInput Button is clicked
 *@param none
 *@return void
 */
void MainWindow::on_browseFileInput_clicked(){

    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir le fichier"), "", tr("Fichiers Textes (*.txt)") );
    if(fileName != ""){
        ui->lineEditInputFile->setText(fileName);
    }
}



/**
 *@brief open the file browser when the browseFileOutput Button is clicked
 *@param none
 *@return void
 */
void MainWindow::on_browseFileOutput_clicked(){

    QString directoryName = QFileDialog::getExistingDirectory(this, tr("Choisir le dossier"), "", QFileDialog::ShowDirsOnly);
    if(directoryName != ""){
        ui->lineEditOutputFile->setText(directoryName);
    }
}



/**
 *@brief set newText as the value of inputFile when the text in lineEditInputFile is changed
 *@param newText, a QString containing the new value of text
 *@return void
 */
void MainWindow::on_lineEditInputFile_textChanged(const QString &newText){

    inputFile = newText;
}



/**
 *@brief set newText as the value of outputDir when the text in lineEditOutputFile is changed
 *@param newText, a QString containing the new value of text
 *@return void
 */
void MainWindow::on_lineEditOutputFile_textChanged(const QString &newText){

    outputDir = newText;
}



/**
 *@brief the fonction that correct the input file
 *@param file_to_input, the file to correct
 *@param directory_to_output, the directory where the corected file will be send
 *@return an exit code
 */
char MainWindow::correctFile(QString file_to_open, QString directory_to_output){

    if(file_to_open.size() == 0){ //if file_to_open is empty

        QMessageBox::warning(this, tr("ATTENTION"),tr("Veuillez sélectionner un fichier a corrigé"));
        return -1;
    }
    else if(directory_to_output.size() == 0){ //if directory_to_output is empty

        QMessageBox::warning(this, tr("ATTENTION"),tr("Veuillez sélectionner un dossier où enregistré le fichier corrigé"));
        return -2;
    }



    QString buffer = file_to_open.left( file_to_open.lastIndexOf(".txt") );

    int X = buffer.lastIndexOf("/");

    QString fileName = "";

    for(int i = X+1; i < buffer.size(); i++){

        fileName += buffer[i];
    }

    QString outputFile_name = fileName + "_EDITED.txt";



    QFile inputFile(file_to_open);

    if(!inputFile.open(QFile::ReadOnly | QFile::Text | QFile::ExistingOnly)){

        QMessageBox::critical(this, tr("ERREUR"),"Le fichier " + fileName + " n'a pas pus être ouvert");
        return -1;
    }

    QTextStream inputStream(&inputFile);

    QString line = inputStream.readAll();

    if(line.size() > 121){

        for(int i = 120; i < line.size(); i+= 121){

            line.insert(i, "\n");
        }
    }



    QFile outputFile(directory_to_output + "/" + outputFile_name);

    if(!outputFile.open(QFile::WriteOnly | QFile::Text) ){

        QMessageBox::critical(this, tr("ERREUR"),"Le fichier " + outputFile_name + " n'a pas pus être créer "
                                                 "veuillez vérifier qu'il vous reste de la mémoire sur votre ordinateur");
        return -2;
    }

    QTextStream outputStream(&outputFile);
    outputStream << line;



    outputFile.flush();
    outputFile.close();

    inputFile.close();

    QMessageBox::information(this, tr("SUCCES"),"Le fichier " + outputFile_name + " a correctement été créer");

    return 0;
}
