#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BankTransfer.h"
#include "Blockchain.h"

Blockchain<BankTransfer> chain(4, 10);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chain.load_transactions_from_csv("/Users/diegopachecoferrel/Documents/CLion/Blockchain/cmake-build-debug/dataset.csv");


    ui->n_block->setMaximum(chain.chain_size());

    ui->index->setText(QString::number(chain.get_block(ui->n_block->value())->get_index()));
    ui->nonce->setText(QString::number(chain.get_block(ui->n_block->value())->get_nonce()));
    ui->transactions->setText(QString::fromStdString(chain.get_block(ui->n_block->value())->transactions_as_string()));
    ui->prev->setText(QString::fromStdString(chain.get_block(ui->n_block->value())->get_prevHash()));
    ui->hash->setText(QString::fromStdString(chain.get_block(ui->n_block->value())->get_hash()));

    ui->modifyBlock->setMaximum(chain.chain_size());
    ui->modifyTrans->setMaximum(chain.get_block(ui->modifyBlock->value())->get_transactions().size());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_sendButton_clicked()
{
    QString emisortext = ui->from->text();
    QString receptortext = ui->to->text();
    QString amounttext = ui->amount->text();


    mount_t amount = amounttext.toFloat();
    string emisor = emisortext.toStdString();
    string receptor = receptortext.toStdString();

    auto transfer = new BankTransfer(emisor, receptor, amount);

    chain.insert_transaction(transfer);

    ui->n_block->setMaximum(chain.chain_size());
    ui->modifyBlock->setMaximum(chain.chain_size());

    int arg1 = ui->n_block->value();
    MainWindow::on_n_block_valueChanged(arg1);
}


void MainWindow::on_showButton_clicked()
{
    QString range_starttext = ui->range_start->text();
    QString range_endtext = ui->range_end->text();
    QString prefixtext = ui->prefix->text();
    QString user_searchtext = ui->user_search->text();
    QString patterntext = ui->pattern->text();

    mount_t range_start = range_starttext.toFloat();
    mount_t range_end = range_endtext.toFloat();
    string prefix = prefixtext.toStdString();
    string user_search = user_searchtext.toStdString();
    string pattern = patterntext.toStdString();

    ui->range_search->clear();
    ui->startwith_search->clear();
    ui->pattern_search->clear();

    ui->maxamount->setText(QString::number(chain.max_amount()));
    ui->minamount->setText(QString::number(chain.min_amount()));
    for(auto elem : chain.range_search(range_start,range_end)){
        if(chain.range_search(range_start,range_end).size() == 0)
            ui->range_search->addItem(QString::fromStdString("Not found"));
        else
            ui->range_search->addItem(QString::number(elem));
    }
    for(auto elem : chain.start_with(prefix)){
        if(chain.start_with(prefix).size() == 0)
            ui->startwith_search->append(QString::fromStdString("Not found"));
        else
            ui->startwith_search->append(QString::fromStdString(elem));
    }
    for(auto elem : chain.contains(pattern)){
        if(chain.contains(pattern).size() == 0)
            ui->pattern_search->append(QString::fromStdString("Not found"));
        else
            ui->pattern_search->append(QString::fromStdString(elem));
    }
    ui->user_cash->setText(QString::number(chain.search(user_search)));
}


void MainWindow::on_n_block_valueChanged(int arg1)
{
    ui->n_block->setMaximum(chain.chain_size());
    ui->index->setText(QString::number(chain.get_block(arg1)->get_index()));
    ui->nonce->setText(QString::number(chain.get_block(arg1)->get_nonce()));
    ui->transactions->setText(QString::fromStdString(chain.get_block(arg1)->transactions_as_string()));
    ui->prev->setText(QString::fromStdString(chain.get_block(arg1)->get_prevHash()));
    ui->hash->setText(QString::fromStdString(chain.get_block(arg1)->get_hash()));
}


void MainWindow::on_modifyButton_clicked()
{
    chain.modify_block(ui->modifyBlock->value(), ui->modifyTrans->value(), new BankTransfer(ui->modifyEmisor->text().toStdString(),ui->modifyReceptor->text().toStdString(), ui->modifyMonto->text().toFloat()));
    int arg1 = ui->n_block->value();
    MainWindow::on_n_block_valueChanged(arg1);
}


void MainWindow::on_modifyBlock_valueChanged(int arg1)
{
    ui->modifyTrans->setMaximum(chain.get_block(arg1)->get_transactions().size());
}

