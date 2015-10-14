#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QDebug>
#include "datajson.h"
#include "settingpreferencias.h"
#include "dialogpre.h"
#include <QSettings>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//
private slots:
    /*!
     * Metodo donde controlamos la mecanica de la aplicación.
     */
     void run();
     /*!
      * Lanza la ventana grafica de la clase DialogPre.
      */
     void lanzarDialogoPreferencias();

private:
    Ui::MainWindow *ui;
    DataJson *_objectDataJson; ///< Puntero DataJson con el que obtenemos los datos de la lectura del fichero Json.
    SettingPreferencias *_objetoSettingPre;///< Puntero SettingPreferencias donde leemos y editamos los datos del setting.
    DialogPre *_objetoDialogoPrefe;///< Puntero de la clase DialogPre, es una clase con entorno grafico para poder seleccionar los ficheros que no se encuentran.
};

#endif // MAINWINDOW_H
