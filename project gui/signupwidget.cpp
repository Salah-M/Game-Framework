#include "signupwidget.h"


signupwidget::signupwidget(QWidget *parent) : QWidget(parent)
{
    firstname_label = new QLabel("First Name");
    lastname_label = new QLabel("Last Name");
    username_label = new QLabel("Username");
    password_label = new QLabel("Password");
    confirmpassword_label = new QLabel("Confirm Password");
    picture_label = new QLabel("Picture");
    gender_label = new QLabel("Gender");
    DateOfBirth_label = new QLabel("Date of Birth");

    firstname_line = new QLineEdit();
    lastname_line = new QLineEdit();
    username_line = new QLineEdit();
    password_line = new QLineEdit();
    password_line->setEchoMode(QLineEdit::Password);
    comfirmpassword_line = new QLineEdit();
    comfirmpassword_line->setEchoMode(QLineEdit::Password);
    messageBox = new QMessageBox();


    password_RegEx = new QRegExp("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])[a-zA-Z0-9]{8,}$");
    password_RegEx->setPatternSyntax(QRegExp::RegExp);



    RB0 = new QRadioButton("male");
    RB1 = new QRadioButton("female");

    C = new QCalendarWidget();

    PB0 = new QPushButton("Sign up");
    PB1 = new QPushButton("Upload Picture");

    HBox = new QHBoxLayout();
    HBox->addWidget(RB0);
    HBox->addWidget(RB1);
    G = new QGroupBox();
    G->setLayout(HBox);

    VBox = new QVBoxLayout();

    VBox->addWidget(firstname_label);
    VBox->addWidget(firstname_line);
    VBox->addWidget(lastname_label);
    VBox->addWidget(lastname_line);
    VBox->addWidget(username_label);
    VBox->addWidget(username_line);
    VBox->addWidget(password_label);
    VBox->addWidget(password_line);
    VBox->addWidget(confirmpassword_label);
    VBox->addWidget(comfirmpassword_line);
    VBox->addWidget(picture_label);
    VBox->addWidget(PB1);
    VBox->addWidget(gender_label);
    VBox->addWidget(G);
    VBox->addWidget(DateOfBirth_label);
    //VBox->addItem(grid);
    VBox->addWidget(C);
    VBox->addWidget(PB0);
    setLayout(VBox);

    QObject::connect(PB0, SIGNAL(clicked(bool)), this, SLOT(signup()));
    QObject::connect(PB1, SIGNAL(clicked(bool)), this, SLOT(image()));

}

void signupwidget::signup()
{
    if (password_line->text() != comfirmpassword_line->text())
    {
        messageBox->critical(0,"Error","Password does not match!");
        messageBox->setFixedSize(500,200);
    }
    else if (!password_RegEx->exactMatch(password_line->text()))
    {
        messageBox->critical(0,"Error","The password should consist of at least 8 characters and contain at least one number, upper and lowercase letters!");
        messageBox->setFixedSize(500,200);
    }
    else if (firstname_line == NULL)
    {
        messageBox->critical(0,"Error","One of the fields is missing!");
        messageBox->setFixedSize(500,200);
    }
    else if (username_line == NULL)
    {
        messageBox->critical(0,"Error","One of the fields is missing!");
        messageBox->setFixedSize(500,200);
    }
    else if (lastname_line == NULL)
    {
        messageBox->critical(0,"Error","One of the fields is missing!");
        messageBox->setFixedSize(500,200);
    }
    else if(imageName == NULL)
    {
        messageBox->critical(0,"Error","One of the fields is missing!");
        messageBox->setFixedSize(500,200);
    }
    else if (!RB0->isChecked() && !RB1->isChecked())
    {
        messageBox->critical(0,"Error","One of the fields is missing!");
        messageBox->setFixedSize(500,200);
    }
    else
    {
        QFile file("/home/eece435l/lab3/repo/project repo/game-platform-group-5/game-platform-group-5/project gui/accounts.txt");
        QString temp;
        file.open(QIODevice::ReadOnly);
        QTextStream in(&file);
        in >> temp;
        qDebug() << temp<<endl;
        QString line = in.readLine();
        qDebug() << line<<endl;
        while (!line.isNull())

        {
            if(temp==username_line->text())
            {
                messageBox->critical(0,"Error","User already exists!");
                messageBox->setFixedSize(500,200);
                return;
            }
            in >> temp;
            line = in.readLine();
            qDebug() << line<<endl;

        }
        file.close();

        QString gender;
        QString dob;
        dob = C->selectedDate().toString();
        if(RB0->isChecked())
        {
            gender="male";
        }
        else if(RB1->isChecked())
        {
            gender="female";
        }

        QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Md5);         // MIGHT BE PROBLEMATIC NEEDS FURTHER TESTING
        hash->addData(password_line->text().toUtf8());
        QString pass;
        pass = hash->result();
        if (file.open(QIODevice::ReadWrite | QIODevice::Append))
        {
            QTextStream stream(&file);
            stream << username_line->text()<<" "<< pass << " " <<firstname_line->text()<<" "<<lastname_line->text()<< " " << gender << " "<< dob <<" "<< imageName<< endl;
            stream.flush();
        }

        this->close();
    }


}

void signupwidget::image()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("images(*.png *.jpg *.jpeg *.bmp)"));
    if(QString::compare(filename,QString())!=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            imageName=filename;
        }
    }
}
