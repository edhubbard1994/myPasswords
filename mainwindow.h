#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_clicked();


    void on_AccountComboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QString newAccount;
    QString newPassword;
    QString path="your_path/user_Accounts";

    void populateComboBox();
    void resetWindow();

    QString encode(QString);

};

#endif // MAINWINDOW_H
