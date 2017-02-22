using System;
using System.Data;
using System.Data.SQLite;
using System.Windows.Forms;
using DuoDuo.Core;
using System.Collections;

namespace DuoDuo
{
    public partial class Form_Account : Form
    {
        public Form_Account()
        {
            InitializeComponent();
            //     sb.DataSource = "bill.db";
            //      connection = new SQLiteConnection(sb.ToString());
            BillData.init();
            BillData.dataGridView = this.dataGridView_Account;
            BillData.pb_show = this.progressBar_show;
        }



        /**
        type 表示账目类型，
        */
        /*
        private void updateDGV(int type,string cmd)
        {
            SQLiteCommand selectCommand = connection.CreateCommand();
            selectCommand.CommandText = cmd;
            SQLiteDataAdapter dataAdapter = new SQLiteDataAdapter();
            dataAdapter.SelectCommand = selectCommand;
            data = new DataTable();
            dataAdapter.Fill(data);
            this.dataGridView_Account.DataSource = data;

            setGridText(type); //设置显示

            SQLiteCommandBuilder builder = new SQLiteCommandBuilder(dataAdapter);
            dataAdapter.UpdateCommand = builder.GetUpdateCommand();
            dataAdapter.InsertCommand = builder.GetInsertCommand();
            dataAdapter.DeleteCommand = builder.GetDeleteCommand();

            dataAdapter.Update(data);
        }
        */
        private void splitContainer1_SplitterMoved(object sender, SplitterEventArgs e)
        {

        }

        private void splitContainer1_Panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void dataGridView_Account_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button_AddPublicBill_Click(object sender, EventArgs e)
        {
            Form m_addInfoForm = new FormAddInfo(1);
            m_addInfoForm.ShowDialog();
        }

        private void button_AddPublicCard_Click(object sender, EventArgs e)
        {
            Form m_addInfoForm = new FormAddInfo(2);
            m_addInfoForm.ShowDialog();
        }

        private void button_AddIndirectBill_Click(object sender, EventArgs e)
        {
            Form m_addInfoForm = new FormAddInfo(3);
            m_addInfoForm.ShowDialog();
        }

        private void button_CheckBill_Click(object sender, EventArgs e)
        {
            MessageBox.Show("稍等~.~");
        }

        private void button_settings_Click(object sender, EventArgs e)
        {

        }

        private void button_sta_Click(object sender, EventArgs e)
        {

        }

        private void button_user_Click(object sender, EventArgs e)
        {
            Form m_addUserForm = new FormUser();
            m_addUserForm.Show();
        }

        private void button_export_Click(object sender, EventArgs e)
        {
            this.contextMenuStrip_export.Show(Cursor.Position.X,Cursor.Position.Y);
        }

        private void button_search_Click(object sender, EventArgs e)
        {
            if (this.checkBox_all.Checked)
            {
                BillData.searchAll(this.comboBox_table.SelectedIndex);
            }
            else
            {
                BillData.startime = this.dateTimePicker_stime.Value.ToString("yyyy-MM-dd");
                BillData.endtime = this.dateTimePicker_etime.Value.ToString("yyyy-MM-dd");
                BillData.search(this.comboBox_table.SelectedIndex, BillData.startime, BillData.endtime);
            }

        }


        /// <summary>
        /// 导出公共经费到excel
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void toolStripMenuItem_public_bill_Click(object sender, EventArgs e)
        {
           BillData.export2excel(1,false);
        }

        /// <summary>
        /// 导出公务卡到excel
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void toolStripMenuItem_public_card_Click(object sender, EventArgs e)
        {
            BillData.export2excel(2, false);
        }

        /// <summary>
        /// 导出间接经费到excel
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void toolStripMenuItem_indirect_bill_Click(object sender, EventArgs e)
        {
            BillData.export2excel(3, false);
        }

        private void ToolStripMenuItem_CurrentData_Click(object sender, EventArgs e)
        {
            BillData.export2excel(4, true);
        }
    }
}
