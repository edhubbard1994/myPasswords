#ifndef START_H
#define START_H

#include <QDialog>

namespace Ui {
class start;
}

class start : public QDialog
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    void CloseEvent(QCloseEvent*);
    ~start();

private slots:
    void loginIsTrue();
    void on_logButton_clicked();

    void on_createButton_clicked();


private:
    Ui::start *ui;
};

#endif // START_H
