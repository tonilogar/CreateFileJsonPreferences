#ifndef DIALOGPRE_H
#define DIALOGPRE_H

#include <QDialog>
#include <QSettings>
#include <QDebug>
#include <QFileDialog>
#include "settingpreferencias.h"

namespace Ui {
class DialogPre;

}

class DialogPre : public QDialog
{
    Q_OBJECT

public:
    /*!
     * Constructor explicito, necesita un puntero nulo.
     */
    explicit DialogPre(QWidget *parent = 0);
    ~DialogPre();
    /*!
     * Obtiene los datos de los lineEdit y los utiliza para modificar los datos del setting.
     */
    void accept();
    /*!
     * Desactiva o activa los widgets relacionados con la imagen met de Catalunya.
     */
    void disableImageCat(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con la imagen met de España.
     */
    void disableImageEsp(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con la imagen met de Francia.
     */
    void disableImageFra(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageSubescenes.exe.
     */
    void disableExeSub(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageGeoTransformation.exe.
     */
    void disableExeImaOpe(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageFootPrintMask.exe.
     */
    void disableExeFootP(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCADBDTMEXTRACTIONCONSOLEVERSION.exe.
     */
    void disableExeExtra(bool disaOrEna);
    /*!
     * Desactiva o activa los widgets relacionados con el ejecutable ICCImageresize.exe.
     */
    void disableExeResi(bool disaOrEna);

private:
    Ui::DialogPre *ui;
    QString _openDirImage;///< Variable que se utiliza como direccion para seleccionar las imagenes met.
    QString _openDirExe;///< Variable que se utiliza como direccion para seleccionar los ejecutables.
    SettingPreferencias *_objetoSettingPre; ///< Puntero a objeto SettingPreferencias.
private slots:
    /*!
     * Lanza una ventana para seleccionar la imagen met de Catalunya.
     */
    void selectMetCat();
    /*!
     * Lanza una ventana para seleccionar la imagen met de España.
     */
    void selectMetEsp();
    /*!
     * Lanza una ventana para seleccionar la imagen met de Francia.
     */
    void selectMetFra();
    /*!
     * Lanza una ventana para seleccionar el ejecutable ICCImageSubescenes.exe.
     */
    void selectExeSub();
    /*!
     * Lanza una ventana para seleccionar el ejecutable ICCImageGeoTransformation.exe.
     */
    void selectExeImaOpe();
    /*!
     * Lanza una ventana para seleccionar el ejecutable ICCImageFootPrintMask.exe.
     */
    void selectExeFootP();
    /*!
     * Lanza una ventana para seleccionar el ejecutable ICCADBDTMEXTRACTIONCONSOLEVERSION.exe.
     */
    void selectExeExtra();
    /*!
     * Lanza una ventana para seleccionar el ejecutable ICCImageresize.exe.
     */
    void selectExeResi();


};

#endif // DIALOGPRE_H
