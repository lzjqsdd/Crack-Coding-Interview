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

namespace DuoDuo
{
    public partial class FormUser : Form
    {

        public FormUser()
        {
            InitializeComponent();

        }

        private void button_save_Click(object sender, EventArgs e)
        {
            try
            {
                int index = this.comboBox_grade.SelectedIndex;
                BillData.usertype = BillData.mgrade[index];
                BillData.adduser = this.textBox_username.Text;

                if (BillData.addUser())
                {
                    MessageBox.Show("添加成功（●'◡'●）");
                    Close();
                }
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message+"--> 重新检查设置( ▼-▼ )");
            }
          
        }
    }
}
