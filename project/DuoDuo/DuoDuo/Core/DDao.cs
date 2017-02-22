using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SQLite;
using System.Windows.Forms;

namespace DuoDuo.Core
{
    class DDao
    {

        public DDao()
        {
            getConnect();
        }

        public void getConnect()
        {
           
        }

        public void getALLPublicBill(DataGridView dgv)
        {
            SQLiteConnection conn = new SQLiteConnection("Data Source=" + "./bill.db");
            conn.Open();
            SQLiteCommand cmd = new SQLiteCommand();
            cmd.CommandText = "select * from public_bill";
            SQLiteDataReader result = cmd.ExecuteReader();
            while (result.Read())
            {

            }
            SQLiteDataAdapter
            conn.Close();
        }
    }
}
