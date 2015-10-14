#ifndef SETTINGPREFERENCIAS_H
#define SETTINGPREFERENCIAS_H

#include <QObject>
#include <QSettings>
#include <QDebug>
class SettingPreferencias : public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructor explicito, necesita un puntero nulo.
     */
    explicit SettingPreferencias(QObject *parent = 0);
    //Getter
    /*!
     * Muestra el path alojado en el setting sobre la variable _pathImageCatSett.
     */
    QString getSettingImageCat();
    /*!
     * Muestra el path alojado en el setting sobre la variable _pathImageEspSett.
     */
    QString getSettingImageEsp();
    /*!
     * Muestra el path alojado en el setting sobre la variable _pathImageFraSett.
     */
    QString getSettingImageFran();
    /*!
     * Muestra el path alojado en el setting sobre la variable exeSubeSett.
     */
    QString getExeSubScene();
    /*!
     * Muestra el path alojado en el setting sobre la variable exeImaOpeGeoSett.
     */
    QString getExeImaOpeGeo();
    /*!
     * Muestra el path alojado en el setting sobre la variable exeFootPrintMaskSett.
     */
    QString getExeFootPrintMask();
    /*!
     * Muestra el path alojado en el setting sobre la variable exeExtractionSett.
     */
    QString getExeExtraction();
    /*!
     * Muestra el path alojado en el setting sobre la variable exeExeResizeSett.
     */
    QString getExeResize();
    /*!
     * comprueba si el valor del setting de _pathImageCatSett esta vacio.
     */
    bool existPathImageCatSett();
    /*!
     * comprueba si el valor del setting de _pathImageEspSett esta vacio.
     */
    bool existPathImageEspSett();
    /*!
     * comprueba si el valor del setting de _pathImageFraSett esta vacio.
     */
    bool existPathImageFraSett();
    /*!
     * comprueba si el valor del setting de _exeSubeSett esta vacio.
     */
    bool existExeSubeSett();
    /*!
     * comprueba si el valor del setting de _exeImaOpeoSett esta vacio.
     */
    bool existExeImaOpeoSett();
    /*!
     * comprueba si el valor del setting de _exeFootPSett esta vacio.
     */
    bool existExeFootPSett();
    /*!
     * comprueba si el valor del setting de _exeExtraSett esta vacio.
     */
    bool existExeExtraSett();
    /*!
     * comprueba si el valor del setting de _exeResiSett esta vacio.
     */
    bool existExeResiSett();


signals:

public slots:

    //setters
    /*!
     * Cambia el path alojado en el setting sobre la variable _pathImageCatSett.
     */
    void setPathImageCatSett(QString pathImageCatSett);
    /*!
     * Cambia el path alojado en el setting sobre la variable _pathImageEspSett.
     */
    void setPathImageEspSett(QString pathImageEspSett);
    /*!
     * Cambia el path alojado en el setting sobre la variable _pathImageFraSett.
     */
    void setPathImageFraSett(QString pathImageFraSett);
    /*!
     * Cambia el path alojado en el setting sobre la variable exeSubeSett..
     */
    void setExeSubeSett(QString exeSubeSett);
    /*!
     * Cambia el path alojado en el setting sobre la variable exeImaOpeGeoSett.
     */
    void setExeImaOpeoSett(QString exeImaOpeoSett);
    /*!
     * Cambia el path alojado en el setting sobre la variable exeFootPrintMaskSett.
     */
    void setExeFootPSett(QString exeFootPSett);
    /*!
     * Cambia el path alojado en el setting sobre la variable exeExtractionSett.
     */
    void setExeExtraSett(QString exeExtraSett);
    /*!
     * Cambia el path alojado en el setting sobre la variable exeExeResizeSett.
     */
    void setExeResiSett(QString exeResiSett);

private:
    QString _pathImageCatSett; ///< Path imagen original del met de Catalunya.
    QString _pathImageEspSett; ///< Path imagen original del met de Espanya.
    QString _pathImageFraSett;///< Path imagen original del met de Francia.
    QString _exeSubeSett; ///< Path del ejecutable SubScene.
    QString _exeImaOpeoSett;///< Path del ejecutable ImaOpeGeo.
    QString _exeFootPSett;///< Path del ejecutable FootPrintMask.
    QString _exeExtraSett;///< Path del ejecutable Extraction.
    QString _exeResiSett;///< Path del ejecutable Resize.
};

#endif // SETTINGPREFERENCIAS_H
