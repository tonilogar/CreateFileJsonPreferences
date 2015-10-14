#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonRun,SIGNAL(clicked()),this,SLOT(run()));
    connect(ui->pushButtonEditPreferences,SIGNAL(clicked()),this,SLOT(lanzarDialogoPreferencias()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::run()
{
    _objectDataJson=new DataJson(this);//Creo el objeto DataJson
    if(!_objectDataJson->existJson())  //Busco si el fichero Json esta en el directorio raiz del ejecutable
    {                                  //Si no esta creo un fichero Json por defecto y si esta leo el fichero Json
        _objectDataJson->createJsonStandard(); //Crear el fichero Json por defecto
    }
    _objectDataJson->readJson();
    if(_objectDataJson->existFiles())
        return;
                else
    {
        lanzarDialogoPreferencias();
        _objectDataJson->createJsonStandard();
    }
}
void MainWindow::lanzarDialogoPreferencias()
{
_objetoDialogoPrefe=new DialogPre(0);
//_objetoDialogoPrefe->disableImageEsp(_objetoSettingPre->existPathImageEspSett());
//_objetoDialogoPrefe->disableExeImaOpe(_objetoSettingPre->existExeImaOpeoSett());
_objetoDialogoPrefe->disableExeExtra(_objetoSettingPre->existExeExtraSett());
_objetoDialogoPrefe->disableExeFootP(_objetoSettingPre->existExeFootPSett());
_objetoDialogoPrefe->disableExeResi(_objetoSettingPre->existExeResiSett());
_objetoDialogoPrefe->disableExeSub(_objetoSettingPre->existExeSubeSett());
_objetoDialogoPrefe->disableImageCat(_objetoSettingPre->existPathImageCatSett());
_objetoDialogoPrefe->disableImageFra(_objetoSettingPre->existPathImageFraSett());
_objetoDialogoPrefe->exec();
}


