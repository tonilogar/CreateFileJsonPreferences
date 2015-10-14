#include "settingpreferencias.h"

SettingPreferencias::SettingPreferencias(QObject *parent) : QObject(parent)
{
QSettings settings("tonilogar","ToolsJson",this);

_pathImageCatSett=settings.value("imagenMetCatalunya").toString();
_pathImageEspSett=settings.value("imagenMetEspanya").toString();
_pathImageFraSett=settings.value("imagenMetFrancia").toString();
_exeSubeSett=settings.value("exeSube").toString();
_exeImaOpeoSett=settings.value("exeImaOpeo").toString();
_exeFootPSett=settings.value("exeFootPrintMask").toString();
_exeExtraSett=settings.value("exeExtraction").toString();
_exeResiSett=settings.value("exeResize").toString();
}

//Getter
QString SettingPreferencias::getSettingImageCat()
{
 return _pathImageCatSett;
}
QString SettingPreferencias::getSettingImageEsp()
{
 return _pathImageEspSett;
}
QString SettingPreferencias::getSettingImageFran()
{
 return _pathImageFraSett;
}
QString SettingPreferencias::getExeSubScene()
{
 return _exeSubeSett;
}
QString SettingPreferencias::getExeImaOpeGeo()
{
return _exeImaOpeoSett;
}
QString SettingPreferencias::getExeFootPrintMask()
{
 return _exeFootPSett;
}
QString SettingPreferencias::getExeExtraction()
{
return _exeExtraSett;
}
QString SettingPreferencias::getExeResize()
{
 return _exeResiSett;
}

//setters
void SettingPreferencias::setPathImageCatSett(QString pathImageCatSett)
{
    QSettings settings("tonilogar","ToolsJson",this);
    settings.setValue("imagenMetCatalunya",pathImageCatSett);
    _pathImageCatSett=pathImageCatSett;
}
void SettingPreferencias::setPathImageEspSett(QString pathImageEspSett)
{
    QSettings settings("tonilogar","ToolsJson",this);
    settings.setValue("imagenMetEspanya",pathImageEspSett);
    _pathImageEspSett=pathImageEspSett;
}
void SettingPreferencias::setPathImageFraSett(QString pathImageFraSett)
{
    QSettings settings("tonilogar","ToolsJson",this);
    settings.setValue("imagenMetFrancia",pathImageFraSett);
    _pathImageFraSett=pathImageFraSett;
}
void SettingPreferencias::setExeSubeSett(QString exeSubeSett)
{
    QSettings settings("tonilogar","ToolsJson",this);
    settings.setValue("exeSube",exeSubeSett);
    _exeSubeSett=exeSubeSett;
}
void SettingPreferencias::setExeImaOpeoSett(QString exeImaOpeoSett)
{
    QSettings settings("tonilogar","ToolsJson",this);
    settings.setValue("exeImaOpeo",exeImaOpeoSett);
    _exeImaOpeoSett=exeImaOpeoSett;
}
void SettingPreferencias::setExeFootPSett(QString exeFootPSett)
{
    QSettings settings("tonilogar","ToolsJson",this);
    settings.setValue("exeFootPrintMask",exeFootPSett);
    _exeFootPSett=exeFootPSett;
}
void SettingPreferencias::setExeExtraSett(QString exeExtraSett)
{
    QSettings settings("tonilogar","ToolsJson",this);
    settings.setValue("exeExtraction",exeExtraSett);
    _exeExtraSett=exeExtraSett;
}
void SettingPreferencias::setExeResiSett(QString exeResiSett)
{
    QSettings settings("tonilogar","ToolsJson",this);
    settings.setValue("exeResize",exeResiSett);
    _exeResiSett=exeResiSett;
}

bool SettingPreferencias::existPathImageCatSett()
{
 if(_pathImageCatSett.isNull() || _pathImageCatSett.isEmpty())
     return false;
         else
     return true;
}

bool SettingPreferencias::existPathImageEspSett()
{
 if(_pathImageEspSett.isNull() || _pathImageEspSett.isEmpty())
     return false;
         else
     return true;
}

bool SettingPreferencias::existPathImageFraSett()
{
    if(_pathImageFraSett.isNull() || _pathImageFraSett.isEmpty())
        return false;
            else
        return true;
}
bool SettingPreferencias::existExeSubeSett()
{
    if(_exeSubeSett.isNull() || _exeSubeSett.isEmpty())
        return false;
            else
        return true;
}


bool SettingPreferencias::existExeImaOpeoSett()
{
    if(_exeImaOpeoSett.isNull() || _exeImaOpeoSett.isEmpty())
        return false;
            else
        return true;
}
bool SettingPreferencias::existExeFootPSett()
{
    if(_exeFootPSett.isNull() || _exeFootPSett.isEmpty())
        return false;
            else
        return true;
}
bool SettingPreferencias::existExeExtraSett()
{
    if(_exeExtraSett.isNull() || _exeExtraSett.isEmpty())
        return false;
            else
        return true;
}
bool SettingPreferencias::existExeResiSett()
{
    if(_exeResiSett.isNull() || _exeResiSett.isEmpty())
        return false;
            else
        return true;
}



