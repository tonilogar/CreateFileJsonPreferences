#include "datajson.h"

DataJson::DataJson()
{

}
DataJson::DataJson(QObject *parent) :
    QObject(parent)
{
    _pathJson=qApp->applicationDirPath()+"/dataAplicationToolsPcot.txt";
    _existImageMetCat=false;
    _existImageMetEsp=false;
    _existImageMetFran=false;
    _existSubScene=false;
    _existImaOpeGeo=false;
    _existFootPrintMask=false;
    _existExtraction=false;
    _existResize=false;
    _objectSettingPref=new SettingPreferencias(this);
}

void DataJson::createJsonStandard()
{
    QJsonObject ambitCat, ambitEsp, ambitFran;
    QJsonObject ejeCat, ejeEsp,ejeFran;
    QJsonArray ejecutablesCat,ejecutablesEsp,ejecutablesFran;

    //Crear QJsonObject ambitCat
    ambitCat.insert("Nombreambito",QJsonValue(QString("Catalunya lidar 2 metres")));
    if(_objectSettingPref->existPathImageCatSett())
    {
        ambitCat.insert("Path",_objectSettingPref->getSettingImageCat());
    }
    else
    {
        ambitCat.insert("Path",QJsonValue(QString("//nas02/treballcompartit/dtmdbdad/BD_CAT2MLID_ET.RF")));
    }
        ambitCat.insert("TamanyoPixel",QJsonValue(int(1)));
    ambitCat.insert("Utm",QJsonValue(int(31)));
    ejeCat.insert("Nombre",QJsonValue(QString("exeExtraction")));
    if(_objectSettingPref->existExeExtraSett())
        {ejeCat.insert("Path",_objectSettingPref->getExeExtraction());}
    else
        {ejeCat.insert("Path",QJsonValue(QString("//nas03/geoproces/dfapplications/ICCDTMOperations/exe/ICCADBDTMEXTRACTIONCONSOLEVERSION.exe")));
    }
            ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeResize")));
    if(_objectSettingPref->existExeResiSett())
        {ejeCat.insert("Path",_objectSettingPref->getExeResize());}
    else
       { ejeCat.insert("Path",QJsonValue(QString("//empuries/PRODUCCIO/DFApplications/ICCImageOperations/exe/ICCImageresize.exe")));
    }
            ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeFootPrintMask")));
    if(_objectSettingPref->existExeFootPSett())
       { ejeCat.insert("Path",_objectSettingPref->getExeFootPrintMask());}
    else
        {ejeCat.insert("Path",QJsonValue(QString("//nas03/geoproces/dfapplications/ICCImageOperations/exe/ICCImageFootPrintMask.exe")));
    }
            ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeSubScene")));
    if(_objectSettingPref->existExeSubeSett())
        {ejeCat.insert("Path",_objectSettingPref->getExeSubScene());}
    else
        {ejeCat.insert("Path",QJsonValue(QString("//nas03/geoproces/dfapplications/ICCImageOperations/exe/ICCImageSubescenes.exe")));
    }
            ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeGeoTransform")));
    if(_objectSettingPref->existExeImaOpeoSett())
        {ejeCat.insert("Path",_objectSettingPref->getExeImaOpeGeo());}
    else
        {ejeCat.insert("Path",QJsonValue(QString("//nas03/geoproces/DFApplications/ICCImageOperationsGeoCorrection/exe/ICCImageGeoTransformation.exe")));
    }
            ejecutablesCat.append(ejeCat);
    ambitCat.insert("Ejecutables",ejecutablesCat);

    //Crear QJsonObject ambitEsp
    ambitEsp.insert("Nombreambito",QJsonValue(QString("Espanya 5 metres")));
    if(_objectSettingPref->existPathImageEspSett())
        {
        ambitEsp.insert("Path",_objectSettingPref->getSettingImageEsp());
    }
    else
       {
        ambitEsp.insert("Path",QJsonValue(QString("//Pedros/Disc_E/Antonio/mosaicMetEspanya.rf")));
    }
    ambitEsp.insert("TamanyoPixel",QJsonValue(int(5)));
    ambitEsp.insert("Utm",QJsonValue(int(30)));
    ejeEsp.insert("Nombre",QJsonValue(QString("exeFootPrintMask")));
    if(_objectSettingPref->existExeFootPSett())
       { ejeEsp.insert("Path",_objectSettingPref->getExeFootPrintMask());}
    else
        {ejeEsp.insert("Path",QJsonValue(QString("//nas03/geoproces/dfapplications/ICCImageOperations/exe/ICCImageFootPrintMask.exe")));
    }
            ejecutablesEsp.append(ejeEsp);
    ejeEsp.insert("Nombre",QJsonValue(QString("exeResize")));
    if(_objectSettingPref->existExeResiSett())
       { ejeEsp.insert("Path",_objectSettingPref->getExeResize());}
    else
        {ejeEsp.insert("Path",QJsonValue(QString("//empuries/PRODUCCIO/DFApplications/ICCImageOperations/exe/ICCImageresize.exe")));
    }
            ejecutablesEsp.append(ejeEsp);
    ejeEsp.insert("Nombre",QJsonValue(QString("exeSubScene")));
    if(_objectSettingPref->existExeSubeSett())
       { ejeEsp.insert("Path",_objectSettingPref->getExeSubScene());}
    else
       { ejeEsp.insert("Path",QJsonValue(QString("//nas03/geoproces/dfapplications/ICCImageOperations/exe/ICCImageSubescenes.exe")));
    }
            ejecutablesEsp.append(ejeEsp);
    ejeEsp.insert("Nombre",QJsonValue(QString("exeGeoTransform")));
    if(_objectSettingPref->existExeImaOpeoSett())
        {ejeEsp.insert("Path",_objectSettingPref->getExeImaOpeGeo());}
    else
        {ejeEsp.insert("Path",QJsonValue(QString("//nas03/geoproces/DFApplications/ICCImageOperationsGeoCorrection/exe/ICCImageGeoTransformation.exe")));
   }
            ejecutablesEsp.append(ejeEsp);
    ambitEsp.insert("Ejecutables",ejecutablesEsp);

    //Crear QJsonObject ambitFran
    ambitFran.insert("Nombreambito",QJsonValue(QString("Francia Farmstar")));
    if(_objectSettingPref->existPathImageFraSett())
       { ambitFran.insert("Path",_objectSettingPref->getSettingImageFran());}
    else
       { ambitFran.insert("Path",QJsonValue(QString("//Pedros/Disc_E/Antonio/MosaicMetFarmstar_NTF_ELIP.rf")));}
    ambitFran.insert("TamanyoPixel",QJsonValue(int(10)));
    ambitFran.insert("Utm",QJsonValue(int(-2)));

    ejeFran.insert("Nombre",QJsonValue(QString("exeFootPrintMask")));
    if(_objectSettingPref->existExeFootPSett())
        {ejeFran.insert("Path",_objectSettingPref->getExeFootPrintMask());}
    else
       { ejeFran.insert("Path",QJsonValue(QString("//nas03/geoproces/dfapplications/ICCImageOperations/exe/ICCImageFootPrintMask.exe")));
    }
            ejecutablesFran.append(ejeFran);

    ejeFran.insert("Nombre",QJsonValue(QString("exeResize")));
    if(_objectSettingPref->existExeResiSett())
        {ejeFran.insert("Path",_objectSettingPref->getExeResize());}
    else
       { ejeFran.insert("Path",QJsonValue(QString("//empuries/PRODUCCIO/DFApplications/ICCImageOperations/exe/ICCImageresize.exe")));
    }
            ejecutablesFran.append(ejeFran);
    ejeFran.insert("Nombre",QJsonValue(QString("exeSubScene")));
    if(_objectSettingPref->existExeSubeSett())
       { ejeFran.insert("Path",_objectSettingPref->getExeSubScene());}
    else
       { ejeFran.insert("Path",QJsonValue(QString("//nas03/geoproces/dfapplications/ICCImageOperations/exe/ICCImageSubescenes.exe")));
    }
            ejecutablesFran.append(ejeFran);
    ejeFran.insert("Nombre",QJsonValue(QString("exeResize")));
    if(_objectSettingPref->existExeResiSett())
        {ejeFran.insert("Path",_objectSettingPref->getExeResize());}
    else
        {ejeFran.insert("Path",QJsonValue(QString("//empuries/PRODUCCIO/DFApplications/ICCImageOperations/exe/ICCImageresize.exe")));
    }
            ejecutablesFran.append(ejeFran);
    ambitFran.insert("Ejecutables",ejecutablesFran);

    QJsonArray array;
    array.prepend((ambitCat));
    array.prepend((ambitFran));
    array.prepend((ambitEsp));
    QJsonDocument documento;
    documento.setArray(array);
    QFile documentoTexto;
    QTextStream value;
    QString PathFileJsonDefecto=qApp->applicationDirPath()+"/dataAplicationToolsPcot.txt";
    documentoTexto.setFileName(PathFileJsonDefecto);
    documentoTexto.open(QFile::WriteOnly | QFile::Text);
    value.setDevice(&documentoTexto);
    value << documento.toJson();
}

void DataJson::createJson()
{
    QJsonObject ambitCat, ambitEsp, ambitFran;
    QJsonObject ejeCat, ejeEsp,ejeFran;
    QJsonArray ejecutablesCat,ejecutablesEsp,ejecutablesFran;

    //Crear QJsonObject ambitCat
    ambitCat.insert("Nombreambito",QJsonValue(QString("Catalunya lidar 2 metres")));
    ambitCat.insert("Path",QJsonValue(QString(getPathImageMetCat())));
    ambitCat.insert("TamanyoPixel",QJsonValue(int(1)));
    ambitCat.insert("Utm",QJsonValue(int(31)));
    ejeCat.insert("Nombre",QJsonValue(QString("exeExtraction")));
    ejeCat.insert("Path",QJsonValue(QString(getExeExtraction())));
    ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeResize")));
    ejeCat.insert("Path",QJsonValue(QString(getExeResize())));
    ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeFootPrintMask")));
    ejeCat.insert("Path",QJsonValue(QString(getExeFootPrintMask())));
    ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeSubScene")));
    ejeCat.insert("Path",QJsonValue(QString(getExeSubScene())));
    ejecutablesCat.append(ejeCat);
    ejeCat.insert("Nombre",QJsonValue(QString("exeGeoTransform")));
    ejeCat.insert("Path",QJsonValue(QString(getExeImaOpeGeo())));
    ejecutablesCat.append(ejeCat);
    ambitCat.insert("Ejecutables",ejecutablesCat);

    //Crear QJsonObject ambitEsp
    ambitEsp.insert("Nombreambito",QJsonValue(QString("Espanya 5 metres")));
    ambitEsp.insert("Path",QJsonValue(QString(getPathImageMetEsp())));
    ambitEsp.insert("TamanyoPixel",QJsonValue(int(5)));
    ambitEsp.insert("Utm",QJsonValue(int(30)));
    ejeEsp.insert("Nombre",QJsonValue(QString("exeFootPrintMask")));
    ejeEsp.insert("Path",QJsonValue(QString(getExeFootPrintMask())));
    ejecutablesEsp.append(ejeEsp);
    ejeEsp.insert("Nombre",QJsonValue(QString("exeResize")));
    ejeEsp.insert("Path",QJsonValue(QString(getExeResize())));
    ejecutablesEsp.append(ejeEsp);
    ejeEsp.insert("Nombre",QJsonValue(QString("exeSubScene")));
    ejeEsp.insert("Path",QJsonValue(QString(getExeSubScene())));
    ejecutablesEsp.append(ejeEsp);
    ejeEsp.insert("Nombre",QJsonValue(QString("exeGeoTransform")));
    ejeEsp.insert("Path",QJsonValue(QString(getExeImaOpeGeo())));
    ejecutablesEsp.append(ejeEsp);
    ambitEsp.insert("Ejecutables",ejecutablesEsp);

    //Crear QJsonObject ambitFran
    ambitFran.insert("Nombreambito",QJsonValue(QString("Francia Farmstar")));
    ambitFran.insert("Path",QJsonValue(QString(getPathImageMetFran())));
    ambitFran.insert("TamanyoPixel",QJsonValue(int(10)));
    ambitFran.insert("Utm",QJsonValue(int(-2)));
    ejeFran.insert("Nombre",QJsonValue(QString("exeFootPrintMask")));
    ejeFran.insert("Path",QJsonValue(QString(getExeFootPrintMask())));
    ejecutablesFran.append(ejeFran);
    ejeFran.insert("Nombre",QJsonValue(QString("exeResize")));
    ejeFran.insert("Path",QJsonValue(QString(getExeResize())));
    ejecutablesFran.append(ejeFran);
    ejeFran.insert("Nombre",QJsonValue(QString("exeSubScene")));
    ejeFran.insert("Path",QJsonValue(QString(getExeSubScene())));
    ejecutablesFran.append(ejeFran);
    ejeFran.insert("Nombre",QJsonValue(QString("exeResize")));
    ejeFran.insert("Path",QJsonValue(QString(getExeResize())));
    ejecutablesFran.append(ejeFran);
    ambitFran.insert("Ejecutables",ejecutablesFran);

    QJsonArray array;
    array.prepend((ambitCat));
    array.prepend((ambitFran));
    array.prepend((ambitEsp));
    QJsonDocument documento;
    documento.setArray(array);
    QFile documentoTexto;
    QTextStream value;
    QString PathFileJsonDefecto=qApp->applicationDirPath()+"/dataAplicationToolsPcot.txt";
    documentoTexto.setFileName(PathFileJsonDefecto);
    documentoTexto.open(QFile::WriteOnly | QFile::Text);
    value.setDevice(&documentoTexto);
    value << documento.toJson();
}

void DataJson::readJson()
{
    QFile archivo(QApplication::applicationDirPath()+"/dataAplicationToolsPcot.txt");
    archivo.open(QFile::ReadOnly | QFile::Text);
    QByteArray contenido=archivo.readAll();
    archivo.close();
    QJsonDocument fileJson=QJsonDocument::fromJson(contenido);
    QJsonArray listaAmbitos=fileJson.array();
    QJsonArray listaExe;
    foreach (QJsonValue registro,listaAmbitos)
    {
        QJsonObject ambito=registro.toObject();
        QString nAmbito=registro.toObject().value("Nombreambito").toString();
        QString pathImage=registro.toObject().value("Path").toString();
        if(nAmbito=="Catalunya lidar 2 metres")
        {
            setPathImageMetCat(pathImage);
            existImageCat();
            listaExe=ambito.value("Ejecutables").toArray();
            foreach (QJsonValue exe,listaExe)
            {
                QString nExe=exe.toObject().value("Nombre").toString();
                QString pathExe=exe.toObject().value("Path").toString();
                if(nExe=="exeExtraction")setExeExtraction(pathExe);
                else if(nExe=="exeResize")setExeResize(pathExe);
                else if(nExe=="exeFootPrintMask")setExeFootPrintMask(pathExe);
                else if(nExe=="exeSubScene")setExeSubScene(pathExe);
                else setExeImaOpeGeo(pathExe);
                existexeExtraction();
                existexeResize();
                existexeFootPrintMask();
                existexeSubScene();
            }
        }
        else if (nAmbito=="Espanya 5 metres")
        {
            setPathImageMetEsp(pathImage);
            existImageEsp();
            listaExe=ambito.value("Ejecutables").toArray();
            foreach (QJsonValue exe,listaExe)
            {
                QString nExe=exe.toObject().value("Nombre").toString();
                QString pathExe=exe.toObject().value("Path").toString();
                if(nExe=="exeResize")setExeResize(pathExe);
                else if(nExe=="exeFootPrintMask")setExeFootPrintMask(pathExe);
                else if(nExe=="exeSubScene")setExeSubScene(pathExe);
                else setExeImaOpeGeo(pathExe);
                existexeResize();
                existexeFootPrintMask();
                existexeSubScene();
                existexeImaOpeGeo();
            }
        }
        else
        {
            setPathImageMetFran(pathImage);
            existImageFra();
            listaExe=ambito.value("Ejecutables").toArray();
            foreach (QJsonValue exe,listaExe)
            {
                QString nExe=exe.toObject().value("Nombre").toString();
                QString pathExe=exe.toObject().value("Path").toString();
                if(nExe=="exeResize")setExeResize(pathExe);
                else if(nExe=="exeFootPrintMask")setExeFootPrintMask(pathExe);
                else setExeSubScene(pathExe);
                existexeResize();
                existexeFootPrintMask();
                existexeSubScene();
            }
        }
    }
}

bool DataJson::existJson()
{
    if (!QFile::exists (QApplication::applicationDirPath()+"/dataAplicationToolsPcot.txt"))
        return false;
    else
        return true;
}

bool DataJson::existFiles()
{
    if(_existImageMetCat && _existImageMetEsp && _existImageMetFran && _existSubScene &&
            _existImaOpeGeo && _existFootPrintMask &&  _existExtraction &&  _existResize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DataJson::existImageCat()
{
    _existImageMetCat=QFile::exists(getPathImageMetCat());
}
void DataJson::existImageEsp()
{
    _existImageMetEsp=QFile::exists(getPathImageMetEsp());
}
void DataJson::existImageFra()
{
    _existImageMetFran=QFile::exists(getPathImageMetFran());
}
void DataJson::existexeSubScene()
{
    if(!_existSubScene) _existSubScene=QFile::exists(getExeSubScene());
}
void DataJson:: existexeImaOpeGeo()
{
    if(!_existImaOpeGeo)  _existImaOpeGeo=QFile::exists(getExeImaOpeGeo());
}
void DataJson::existexeFootPrintMask()
{
    if(!_existFootPrintMask)  _existFootPrintMask=QFile::exists(getExeFootPrintMask());
}
void DataJson::existexeExtraction()
{
    if(!_existExtraction)  _existExtraction=QFile::exists(getExeExtraction());
}
void DataJson::existexeResize()
{
    if(!_existResize)  _existResize=QFile::exists(getExeResize());
}

//
//Getter///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString DataJson::getPathImageMetCat()
{
    return _pathImageMetCat;
}

QString DataJson::getPathImageMetEsp()
{
    return _pathImageMetEsp;
}
QString DataJson::getPathImageMetFran()
{
    return _pathImageMetFran;
}
QString DataJson::getPathJson()
{
    return _pathJson;
}
QString DataJson::getExeSubScene()
{
    return _exeSubScene;
}
QString DataJson::getExeImaOpeGeo()
{
    return _exeImaOpeGeo;
}
QString DataJson::getExeFootPrintMask()
{
    return _exeFootPrintMask;
}
QString DataJson::getExeExtraction()
{
    return _exeExtraction;
}
QString DataJson::getExeResize()
{
    return _exeResize;
}
//
//setters/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DataJson::setPathImageMetCat(QString pathImageMetCat)
{
    _pathImageMetCat=pathImageMetCat;
}
void DataJson::setPathImageMetEsp(QString pathImageMetEsp)
{
    _pathImageMetEsp=pathImageMetEsp;
}
void DataJson::setPathImageMetFran(QString pathImageMetFran)
{
    _pathImageMetFran=pathImageMetFran;
}
void DataJson::setPathJson(QString pathJson)
{
    _pathJson=pathJson;
}
void DataJson::setExeSubScene(QString exeSubScene)
{
    _exeSubScene=exeSubScene;
}
void DataJson::setExeImaOpeGeo(QString exeImaOpeGeo)
{
    _exeImaOpeGeo=exeImaOpeGeo;
}
void DataJson::setExeFootPrintMask(QString exeFootPrintMask)
{
    _exeFootPrintMask=exeFootPrintMask;
}
void DataJson::setExeExtraction(QString exeExtraction)
{
    _exeExtraction=exeExtraction;
}
void DataJson::setExeResize(QString exeResize)
{
    _exeResize=exeResize;
}
