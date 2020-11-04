#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include "signupwidget.h"
#include "signinwidget.h"
#include "account.h"
#include <QCryptographicHash>

class mainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit mainWidget(QWidget *parent = nullptr);
    QLabel *label0;
    QLabel *label1;
    QLineEdit *line0;
    QLineEdit *line1;
    QPushButton *PB0;
    QPushButton *PB1;
    QPushButton *PB2;
    QVBoxLayout *VBox;
    signupwidget *sup;
    account *a;
    signinwidget *sin;    QMessageBox *messageBox;

    public slots:
    void signin();
    void signup();
    void playAsGuest();




signals:


};

#endif // MAINWIDGET_H
