#ifndef DATAJSON_H
#define DATAJSON_H

#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QApplication>
#include "settingpreferencias.h"
#include "dialogpre.h"
class DataJson : public QObject
{
public:
    DataJson();
    /*!
     * Constructor, necesita un puntero nulo.
     */
    DataJson(QObject *parent = 0);
    /*!
     * Creo el fichero Json por defecto.
     */
    void createJsonStandard();
    /*!
     * Creo el fichero Json.
     */
    void createJson();
    /*!
     * Lee el fichero Json y asigna los valores de las variables.
     */
    void readJson();
    /*!
     * compruebo si el fichero Json existe.
     */
    bool existJson();
    /*!
     * compruebo si los paths de imagen y ejecutables existen.
     */
    bool existFiles();

    //Getter
    /*!
     * Muestra la imagen origen del met de Catalunya.
     */
    QString getPathImageMetCat();
    /*!
     * Muestra la imagen origen del met de Espanya.
     */
    QString getPathImageMetEsp();
    /*!
     * Muestra la imagen origen del met de França.
     */
    QString getPathImageMetFran();
    /*!
     * Muestra el path del fichero Json.
     */
    QString getPathJson();
    /*!
     * Muestra el path del ejecutable SubScene.
     */
    QString getExeSubScene();
    /*!
     * Muestra el path del ejecutable ImaOpeGeo.
     */
    QString getExeImaOpeGeo();
    /*!
     * Muestra el path del ejecutable FootPrintMask.
     */
    QString getExeFootPrintMask();
    /*!
     * Muestra el path del ejecutable Extraction.
     */
    QString getExeExtraction();
    /*!
     * Muestra el path del ejecutable ExeResize.
     */
    QString getExeResize();
    /*!
     * Comprueba si la imagen met de Catalunya existe.
     */
    void existImageCat();
    /*!
     * Comprueba si la imagen met de Espanya existe.
     */
    void existImageEsp();
    /*!
     * Comprueba si la imagen met de Francia existe.
     */
    void existImageFra();
    /*!
     * Comprueba el ejecutable subscene existe.
     */
    void existexeSubScene();
    /*!
     * Comprueba el ejecutable ICCImageGeoTransformation existe.
     */
    void existexeImaOpeGeo();
    /*!
     * Comprueba el ejecutable footPrintMask existe.
     */
    void existexeFootPrintMask();
    /*!
     * Comprueba el ejecutable extraction existe.
     */
    void existexeExtraction();
    /*!
     * Comprueba el ejecutable resize existe.
     */
    void existexeResize();

signals:

public slots:
    //setters
    /*!
     * Cambia la imagen origen del met de Catalunya.
     */
    void setPathImageMetCat(QString pathImageMetCat);
    /*!
     * Cambia la imagen origen del met de Espanya.
     */
    void setPathImageMetEsp(QString pathImageMetEsp);
    /*!
     * Cambia la imagen origen del met de França.
     */
    void setPathImageMetFran(QString pathImageMetFran);
    /*!
     * Cambia el path del fichero Json.
     */
    void setPathJson(QString pathJson);
    /*!
     * Cambia el path del ejecutable SubScene.
     */
    void setExeSubScene(QString exeSubScene);
    /*!
     * Cambia el path del ejecutable ImaOpeGeo.
     */
    void setExeImaOpeGeo(QString exeImaOpeGeo);
    /*!
     * Cambia el path del ejecutable FootPrintMask.
     */
    void setExeFootPrintMask(QString exeFootPrintMask);
    /*!
     * Cambia el path del ejecutable Extraction.
     */
    void setExeExtraction(QString exeExtraction);
    /*!
     * Cambia el path del ejecutable Resize.
     */
    void setExeResize(QString exeResize);

private:
    QString _pathJson;///< Path fichero Json
    QString _pathImageMetCat; ///< Path imagenn original del met de Catalunya.
    QString _pathImageMetEsp; ///< Path imagenn original del met de Espanya.
    QString _pathImageMetFran;///< Path imagenn original del met de Francia.
    QString _exeSubScene; ///< Path del ejecutable SubScene.
    QString _exeImaOpeGeo;///< Path del ejecutable ImaOpeGeo.
    QString _exeFootPrintMask;///< Path del ejecutable FootPrintMask.
    QString _exeExtraction;///< Path del ejecutable Extraction.
    QString _exeResize;///< Path del ejecutable Resize.
    bool _existImageMetCat;///< Boleano existe o no existe la imagen de Catalunya.
    bool _existImageMetEsp; ///< Boleano existe o no existe la imagen de Espanya.
    bool _existImageMetFran;///< Boleano existe o no existe la imagen de Francia.
    bool _existSubScene; ///< Boleano existe o no existe el ejecutable SubScene.
    bool _existImaOpeGeo;///< Boleano existe o no existe el ejecutable ImaOpeGeo.
    bool _existFootPrintMask;///< Boleano existe o no existe el ejecutable FootPrintMask.
    bool _existExtraction;///< Boleano existe o no existe el ejecutable Extraction.
    bool _existResize;///< Boleano existe o no existe el ejecutable Resize.
    SettingPreferencias *_objectSettingPref;///< Puntero a objeto SettingPreferencias
    DialogPre _objectDialogPre;///< Puntero a objeto DialogPre
};

#endif // DATAJSON_H
