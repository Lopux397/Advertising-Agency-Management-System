#pragma once

#include <QMainWindow>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
private:
    Q_OBJECT
    std::unique_ptr<Ui::MainWindow> ui;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
};
