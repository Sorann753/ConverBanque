/**
 * @file    titre.cpp
 * @brief   a HMI program to edit accounting file in one line to lines of 120 characters
 * @author  Arthus DORIATH (Sorann753)
 * @date    05/05/2021
 * @version 0.1
 */

#include "mainwindow.hpp"
#include <QApplication>



/**
 *@brief the main function in the code
 *@param argc, the number of arguments passed to the program
 *@param argv, a array of the arguments passed to the program
 *@return a exit code
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
