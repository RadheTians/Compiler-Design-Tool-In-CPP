#ifndef COMPILER_H
#define COMPILER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Compiler; }
QT_END_NAMESPACE

class Compiler : public QMainWindow
{
    Q_OBJECT

public:
    Compiler(QWidget *parent = nullptr);
    ~Compiler();

private slots:
    void on_fst_clicked();

    void on_flw_clicked();

    void on_faf_clicked();

    void on_lex_clicked();

    void on_lr_clicked();

    void on_lf_clicked();

    void on_rd_clicked();

    void on_slr_clicked();

private:
    Ui::Compiler *ui;
};
#endif // COMPILER_H
