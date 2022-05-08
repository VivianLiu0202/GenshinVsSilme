#ifndef RULE_H
#define RULE_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QLabel>

namespace Ui {
class Rule;
}

class Rule : public QWidget
{
    Q_OBJECT

public:
    explicit Rule(QWidget *parent = 0);  
    ~Rule();

private slots:
    void on_pushButton_clicked();
signals:
    void mySignal();

private:
    Ui::Rule *ui;
};

#endif // RULE_H
