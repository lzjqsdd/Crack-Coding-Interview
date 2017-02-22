using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using DuoDuo.Core;
using System.Collections;

namespace DuoDuo
{
    public partial class FormAddInfo : Form
    {

        private int typee;
        private ArrayList userList;
        public FormAddInfo()
        {
            InitializeComponent();
        }

        public FormAddInfo(int type)
        {

            InitializeComponent();
            this.typee = type;
            if (type == 1)
            {
                this.comboBox_ReturnPerson.Enabled = false;
                this.dateTimePicker_ReturnDate.Enabled = false;
                this.Text = "新增公共经费";
            }
            else if (type == 2)
            {
                this.radioButton_type1.Enabled = false;
                this.radioButton_type2.Enabled = false;
                this.Text = "新增公务卡经费";
            }
            else if (type == 3)
            {
                this.comboBox_ReturnPerson.Enabled = false;
                this.dateTimePicker_ReturnDate.Enabled = false;
                this.radioButton_type1.Enabled = false;
                this.radioButton_type2.Enabled = false;
                this.Text = "新增间接经费";
            }

            userList = BillData.getUser();
            foreach (string user in userList)
            {
                comboBox_user.Items.Add(user);
                comboBox_ReturnPerson.Items.Add(user);
            }
        }

        private void button_save_Click(object sender, EventArgs e)
        {
            BillData.emptyData();
            BillData.usedate = this.dateTimePicker_UseDate.Value.ToString("yyyy-MM-dd");
            BillData.returndate = this.dateTimePicker_ReturnDate.Value.ToString("yyyy-MM-dd");

            BillData.money = Convert.ToDouble(this.textBox_Number.Text);
            //      BillData.returnperson = comboBox_ReturnPerson.SelectedValue as string;
            //      BillData.user = comboBox_user.SelectedValue as string;
            BillData.returnperson = comboBox_ReturnPerson.Text;
            BillData.user = comboBox_user.Text;
            BillData.reason = this.textBox_Reason.Text;
            BillData.type = this.radioButton_type1.Checked ? 1 : -1;
            if (typee == 1)
            {
                if (BillData.insertPublicBill())
                {
                    BillData.updatePublicBill();
                }
            }

            else if (typee == 2)
            {
                if (BillData.insertPublicCard())
                {
                    BillData.updatePublicCard();
                }
            }
            else if (typee == 3)
            {
                if (BillData.insertIndirectBill())
                {
                    BillData.updateIndirectBill();
                }
            }
            Close();
        }

        private void money_onKeyPress(object sender, KeyPressEventArgs e)
        {
            if (!(Char.IsNumber(e.KeyChar)) && e.KeyChar != (char)8 && e.KeyChar!='.')
                e.Handled = true;
        }
    }
}
