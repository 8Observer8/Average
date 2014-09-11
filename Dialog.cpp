
#include <QMessageBox>
#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_resultButton_clicked()
{
    bool ok;

    // Input
    double a = ui->aLineEdit->text().toDouble( &ok );
    if ( !ok ) {
        QMessageBox::information( this, tr( "Ошибка" ), tr( "Вы ввели некорректные данные" ) );
        return;
    }
    double b = ui->bLineEdit->text().toDouble( &ok );
    if ( !ok ) {
        QMessageBox::information( this, tr( "Ошибка" ), tr( "Вы ввели некорректные данные" ) );
        return;
    }

    // Result
    double c = ( a + b ) / 2.0;

    // Output
    ui->cLineEdit->setText( QString::number( c ) );
}
