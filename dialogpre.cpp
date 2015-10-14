#include "dialogpre.h"
#include "ui_dialogpre.h"

DialogPre::DialogPre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPre)
{

    ui->setupUi(this);
    _openDirImage=qApp->applicationDirPath();
    _openDirExe="//nas03/geoproces/DFApplications";
    _objetoSettingPre=new SettingPreferencias(this);
    connect(ui->pushButtonCatalunya,SIGNAL(clicked()),this,SLOT(selectMetCat()));
    connect(ui->pushButtonEspanya,SIGNAL(clicked()),this,SLOT(selectMetEsp()));
    connect(ui->pushButtonFrancia,SIGNAL(clicked()),this,SLOT(selectMetFra()));
    connect(ui->pushButtonExtraction,SIGNAL(clicked()),this,SLOT(selectExeExtra()));
    connect(ui->pushButtonFootPrintMask,SIGNAL(clicked()),this,SLOT(selectExeFootP()));
    connect(ui->pushButtonGeoTransformation,SIGNAL(clicked()),this,SLOT(selectExeImaOpe()));
    connect(ui->pushButtonResize,SIGNAL(clicked()),this,SLOT(selectExeResi()));
    connect(ui->pushButtonSubescene,SIGNAL(clicked()),this,SLOT(selectExeSub()));
}

DialogPre::~DialogPre()
{
    delete ui;
}

void DialogPre::selectMetCat()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona archivo met de Cataluña",
                                               _openDirImage,"Archivo (*.rf)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditCatlunya->setText(path);
     _openDirImage=path;
}
void DialogPre::selectMetEsp()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona archivo met de España",
                                                _openDirImage,"Archivo (*.rf)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditEspanya->setText(path);
    _openDirImage=path;
}
void DialogPre::selectMetFra()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona archivo met de Francia",
                                                _openDirImage,"Archivo (*.rf)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditFrancia->setText(path);
    _openDirImage=path;
}
void DialogPre::selectExeSub()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona el ejecutable ICCImageSubescenes.exe",
                                               _openDirExe,"Archivo (*.exe)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditSubescene->setText(path);
     _openDirExe=path;
}
void DialogPre::selectExeImaOpe()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona el ejecutable ICCImageGeoTransformation.exe",
                                              _openDirExe,"Archivo (*.exe)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditGeoTransformation->setText(path);
    _openDirExe=path;
}
void DialogPre::selectExeFootP()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona el ejecutable ICCImageFootPrintMask.exe",
                                              _openDirExe,"Archivo (*.exe)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditFootPrintMask->setText(path);
    _openDirExe=path;
}
void DialogPre::selectExeExtra()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona el ejecutable ICCADBDTMEXTRACTIONCONSOLEVERSION.exe",
                                              _openDirExe,"Archivo (*.exe)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditExtraction->setText(path);
    _openDirExe=path;
}
void DialogPre::selectExeResi()
{
    QString path=QFileDialog::getOpenFileName(this,"Selecciona el ejecutable ICCImageresize.exe",
                                              _openDirExe,"Archivo (*.exe)");
    if(path.isNull() || path.isEmpty())return;
    ui->lineEditResize->setText(path);
    _openDirExe=path;
}
void DialogPre::accept()
{
    _objetoSettingPre->setPathImageCatSett(ui->lineEditCatlunya->text());
    _objetoSettingPre->setPathImageEspSett(ui->lineEditEspanya->text());
    _objetoSettingPre->setPathImageFraSett(ui->lineEditFrancia->text());
    _objetoSettingPre->setExeExtraSett(ui->lineEditExtraction->text());
    _objetoSettingPre->setExeFootPSett(ui->lineEditFootPrintMask->text());
    _objetoSettingPre->setExeImaOpeoSett(ui->lineEditGeoTransformation->text());
    _objetoSettingPre->setExeResiSett(ui->lineEditResize->text());
    _objetoSettingPre->setExeSubeSett(ui->lineEditSubescene->text());
    QDialog::accept();
}

void DialogPre::disableImageCat(bool disaOrEna)
{
 ui->pushButtonCatalunya->setDisabled(disaOrEna);
 ui->labelCatalunya->setDisabled(disaOrEna);
 ui->lineEditCatlunya->setDisabled(disaOrEna);
}
void DialogPre::disableImageEsp(bool disaOrEna)
{
    ui->pushButtonEspanya->setDisabled(disaOrEna);
    ui->labelEspanya->setDisabled(disaOrEna);
    ui->lineEditEspanya->setDisabled(disaOrEna);
}
void DialogPre::disableImageFra(bool disaOrEna)
{
    ui->pushButtonFrancia->setDisabled(disaOrEna);
    ui->labelFrancia->setDisabled(disaOrEna);
    ui->lineEditFrancia->setDisabled(disaOrEna);
}
void DialogPre::disableExeSub(bool disaOrEna)
{
    ui->pushButtonSubescene->setDisabled(disaOrEna);
    ui->labelSubescene->setDisabled(disaOrEna);
    ui->lineEditSubescene->setDisabled(disaOrEna);
}
void DialogPre::disableExeImaOpe(bool disaOrEna)
{
    ui->pushButtonGeoTransformation->setDisabled(disaOrEna);
    ui->labelGeoTransformation->setDisabled(disaOrEna);
    ui->lineEditGeoTransformation->setDisabled(disaOrEna);
}
void DialogPre::disableExeFootP(bool disaOrEna)
{
    ui->pushButtonFootPrintMask->setDisabled(disaOrEna);
    ui->labelFootPrintMask->setDisabled(disaOrEna);
    ui->lineEditFootPrintMask->setDisabled(disaOrEna);
}
void DialogPre::disableExeExtra(bool disaOrEna)
{
    ui->pushButtonExtraction->setDisabled(disaOrEna);
    ui->labelExtraction->setDisabled(disaOrEna);
    ui->lineEditExtraction->setDisabled(disaOrEna);
}
void DialogPre::disableExeResi(bool disaOrEna)
{
    ui->pushButtonResize->setDisabled(disaOrEna);
    ui->labelResize->setDisabled(disaOrEna);
    ui->lineEditResize->setDisabled(disaOrEna);
}
