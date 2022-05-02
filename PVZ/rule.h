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
    //void sendSlot();
    ~Rule();

/*signals:
    void mySignal();//子界面发送信号*/

private:
    Ui::Rule *ui;
    //QPushButton *pushButtonBackForm;
};

#endif // RULE_H
