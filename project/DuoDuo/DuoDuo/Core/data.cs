using System.Data.SQLite;
using System.Data;
using System.Windows.Forms;
using System;
using System.Collections;
using System.IO;
using Microsoft.Office.Interop.Excel;

namespace DuoDuo.Core
{
    public static class BillData
    {

        //插入的数据变量
        public static string id = string.Empty;
        public static double money = 0;
        public static string usedate = string.Empty;
        public static string returndate = string.Empty;
        public static string user = string.Empty;
        public static int type = -1; //默认为支出
        public static string returnperson = string.Empty;
        public static string reason = string.Empty;
        public static double total = 0;

        public static string adduser = string.Empty; //包含的用户
        public static string usertype = string.Empty;
        public static string[] mgrade = new string[7];
        public static string[] tname = new string[3];

        public static string startime = string.Empty;
        public static string endtime = string.Empty;

        /// <summary>
        /// 数据库相关
        /// </summary>
        private static SQLiteConnection connection = null;

        private static SQLiteConnectionStringBuilder sb = new SQLiteConnectionStringBuilder();


        private static string cmd_all_public_bill = "select *from public_bill";
        private static string cmd_all_public_card = "select *from public_card";
        private static string cmd_all_indirect_bill = "select *from indirect_bill";

        public static DataGridView dataGridView;
        public static ProgressBar pb_show;


        /// <summary>
        /// 初始化数据
        /// </summary>
        public static void init()
        {
            sb.DataSource = "bill.db";
            connection = new SQLiteConnection(sb.ToString());

            mgrade[0] = "研一";
            mgrade[1] = "研二";
            mgrade[2] = "研三";
            mgrade[3] = "博一";
            mgrade[4] = "博二";
            mgrade[5] = "博三";
            mgrade[6] = "老师";

            tname[0] = "public_bill";
            tname[1] = "public_card";
            tname[2] = "indirect_bill";
        }

        public static void updatePublicBill()
        {
            updateDGV(1, cmd_all_public_bill);
        }

        public static void updatePublicCard()
        {
            updateDGV(2, cmd_all_public_card);
        }

        public static void updateIndirectBill()
        {
            updateDGV(3, cmd_all_indirect_bill);
        }



        /// <summary>
        /// 更新表格数据
        /// </summary>
        /// <param name="type">表索引</param>
        /// <param name="cmd">sql语句</param>
        private static void updateDGV(int type, string cmd)
        {
            SQLiteCommand selectCommand = connection.CreateCommand();
            selectCommand.CommandText = cmd;
            SQLiteDataAdapter dataAdapter = new SQLiteDataAdapter();
            dataAdapter.SelectCommand = selectCommand;
            System.Data.DataTable data = new System.Data.DataTable();
            dataAdapter.Fill(data);
            dataGridView.DataSource = data;

            setGridText(type);

    //        SQLiteCommandBuilder builder = new SQLiteCommandBuilder(dataAdapter);
    //        dataAdapter.Update(data);
        }


        /// <summary>
        /// 更新表格显示信息
        /// </summary>
        /// <param name="type"></param>
        private static void setGridText(int type)
        {
            try
            {
                if (type == 1)
                {
                    dataGridView.Columns[0].HeaderCell.Value = "编号";
                    dataGridView.Columns[1].HeaderCell.Value = "使用时间";
                    dataGridView.Columns[2].HeaderCell.Value = "使用人";
                    dataGridView.Columns[3].HeaderCell.Value = "收入/支出";
                    dataGridView.Columns[4].HeaderCell.Value = "金额";
                    dataGridView.Columns[5].HeaderCell.Value = "用途";
                    dataGridView.Columns[6].HeaderCell.Value = "结余";
                }
                else if (type == 2)
                {
                    dataGridView.Columns[0].HeaderCell.Value = "编号";
                    dataGridView.Columns[1].HeaderCell.Value = "使用时间";
                    dataGridView.Columns[2].HeaderCell.Value = "使用人";
                    dataGridView.Columns[3].HeaderCell.Value = "金额";
                    dataGridView.Columns[4].HeaderCell.Value = "用途";
                    dataGridView.Columns[5].HeaderCell.Value = "归还日期";
                    dataGridView.Columns[6].HeaderCell.Value = "归还人";
                }
                else if (type == 3)
                {
                    dataGridView.Columns[0].HeaderCell.Value = "编号";
                    dataGridView.Columns[1].HeaderCell.Value = "使用时间";
                    dataGridView.Columns[2].HeaderCell.Value = "使用人";
                    dataGridView.Columns[3].HeaderCell.Value = "金额";
                    dataGridView.Columns[4].HeaderCell.Value = "用途";

                }
            }
            catch (Exception e)
            {
                MessageBox.Show("界面设置数据格式错误！" + e.Message);
            }
        }

        /// <summary>
        /// 清空所有缓存数据
        /// </summary>
        public static void emptyData()
        {
            id = string.Empty;
            money = 0;
            usedate = string.Empty;
            returndate = string.Empty;
            user = string.Empty;
            type = -1;
            returnperson = string.Empty;
            reason = string.Empty;
            total = 0;
        }

        /// <summary>
        /// 增加公共经费记录
        /// </summary>
        /// <returns></returns>
        public static bool insertPublicBill()
        {
            //如果为1，表示收入，total加。
            try
            {
                connection.Open();
                SQLiteCommand cmd = new SQLiteCommand(connection);

                string sql_query = "select total from public_bill order by id desc limit 0,1";
                cmd.CommandText = sql_query;
                SQLiteDataReader reader = cmd.ExecuteReader();
                reader.Read();
                double m_total = reader.GetDouble(0);
                total = money * type + m_total;
                reader.Close();

                string mtype = (type == 1 ? "收入" : "支出");
                string sql_insert = "insert into public_bill (money,type,usedate,user,reason,total) values('" + money + "','" + mtype + "','" + usedate + "','" + user + "','" + reason + "','" + total.ToString() + "')";
                cmd.CommandText = sql_insert;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (DataException e)
            {
                MessageBox.Show("公共经费数据格式错误By lvzejun" + e.Message);
                return false;
            }
            return true;
        }

        /// <summary>
        /// 增加公务卡记录
        /// </summary>
        /// <returns></returns>
        public static bool insertPublicCard()
        {
            //如果为1，表示收入，total加。
            try
            {
                connection.Open();
                SQLiteCommand cmd = new SQLiteCommand(connection);

                string sql_query = "select total from public_bill order by id desc limit 0,1";
                cmd.CommandText = sql_query;
                SQLiteDataReader reader = cmd.ExecuteReader();
                reader.Read();
                double m_total = reader.GetDouble(0);
                total = money * type + m_total;
                reader.Close();

                string mtype = (type == 1 ? "收入" : "支出");
                string sql_insert = "insert into public_card (money,usedate,user,reason,rdate,ruser) values('" + money + "','" + usedate + "','" + user + "','" + reason + "','" + returndate + "','" + returnperson + "')";
                cmd.CommandText = sql_insert;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (DataException e)
            {
                MessageBox.Show("公务卡数据格式错误By lvzejun" + e.Message);
                return false;
            }
            return true;
        }



        /// <summary>
        /// 插入间接经费记录
        /// </summary>
        /// <returns></returns>
        public static bool insertIndirectBill()
        {
            //如果为1，表示收入，total加。
            try
            {
                connection.Open();
                SQLiteCommand cmd = new SQLiteCommand(connection);
                string sql_insert = "insert into indirect_bill (money,usedate,user,reason) values('" + money + "','" + usedate + "','" + user + "','" + reason + "')";
                cmd.CommandText = sql_insert;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (DataException e)
            {
                MessageBox.Show("间接经费数据格式错误By lvzejun" + e.Message);
                return false;
            }
            return true;
        }


        /// <summary>
        /// 增加系统涉及的用户
        /// </summary>
        /// <returns></returns>
        public static bool addUser()
        {
            try
            {
                connection.Open();
                SQLiteCommand cmd = new SQLiteCommand(connection);
                string sql_insert = "insert into user (username,grade) values('" + adduser + "','" + usertype + "')";
                cmd.CommandText = sql_insert;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (DataException e)
            {
                MessageBox.Show("间接经费数据格式错误By lvzejun" + e.Message);
                return false;
            }
            return true;
        }

        /// <summary>
        /// 获取涉及的所有用户。
        /// </summary>
        /// <returns></returns>
        public static ArrayList getUser()
        {
            ArrayList userlist = new ArrayList();
            try
            {
                connection.Open();
                SQLiteCommand cmd = new SQLiteCommand(connection);
                string sql_insert = "select username from user";
                cmd.CommandText = sql_insert;
                SQLiteDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    userlist.Add(reader.GetString(0));
                }
                reader.Close();
                connection.Close();
            }
            catch (DataException e)
            {
                MessageBox.Show("间接经费数据格式错误By lvzejun" + e.Message);
            }
            return userlist;
        }

        /// <summary>
        /// 根据日期条件查询
        /// </summary>
        /// <param name="tableIndex"></param>
        /// <param name="starttime"></param>
        /// <param name="endtime"></param>
        /// <returns></returns>
        public static ArrayList search(int tableIndex, string starttime, string endtime)
        {
            ArrayList userlist = new ArrayList();
            try
            {
                string sql_query = "SELECT * from " + BillData.tname[tableIndex] + " where strftime('%s',usedate) between strftime('%s','" + startime + "') and strftime('%s','" + endtime + "')";
                updateDGV(tableIndex + 1, sql_query);
            }
            catch (DataException e)
            {
                MessageBox.Show("间接经费数据格式错误By lvzejun" + e.Message);
            }
            return userlist;
        }


        /// <summary>
        /// 查询所有的数据，无条件
        /// </summary>
        /// <param name="tableIndex">表名，这里用数组索引表示</param>
        /// <returns></returns>
        public static ArrayList searchAll(int tableIndex)
        {
            ArrayList userlist = new ArrayList();
            try
            {
                string sql_query = "SELECT * from " + BillData.tname[tableIndex];
                updateDGV(tableIndex + 1, sql_query);
            }
            catch (DataException e)
            {
                MessageBox.Show("查询所有数据时出现格式错误By lvzejun" + e.Message);
            }
            return userlist;
        }

        /// <summary>
        /// 导出excel
        /// </summary>
        /// <param name="tableIndex">0,1,2三种</param>
        public static void export2excel(int tableIndex,bool currentData)
        {
            //判断是否导出条件查询的结果。
            if (!currentData)
            {
                if (tableIndex == 1)
                    updatePublicBill();
                else if (tableIndex == 2)
                    updatePublicCard();
                else if (tableIndex == 3)
                    updateIndirectBill();
            }

            if (dataGridView.Rows.Count == 0)
            {
                MessageBox.Show(" 没有数据可供导出！", "提示信息", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            else
            {
                SaveFileDialog savedialog = new SaveFileDialog();
                savedialog.DefaultExt = "xlsx";
                savedialog.Filter = "microsoft office execl files (*.xlsx)|*.xlsx";
                savedialog.FilterIndex = 0;
                savedialog.RestoreDirectory = true;
                savedialog.Title = "导出数据到excel表格";
                savedialog.ShowDialog();
                if (savedialog.FileName.IndexOf(":") < 0) return; //被点了取消  
                //Microsoft.office.interop.excel.application xlapp = new microsoft.office.interop.excel.application();
                Microsoft.Office.Interop.Excel.Application xlapp = new Microsoft.Office.Interop.Excel.Application();
                if (xlapp == null)
                {
                    MessageBox.Show("可能您的机子未安装excel，无法创建excel对象！", "系统提示 ", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                Microsoft.Office.Interop.Excel.Workbooks workbooks = xlapp.Workbooks;
                Microsoft.Office.Interop.Excel.Workbook workbook = workbooks.Add(Microsoft.Office.Interop.Excel.XlWBATemplate.xlWBATWorksheet);
                Microsoft.Office.Interop.Excel.Worksheet worksheet = (Microsoft.Office.Interop.Excel.Worksheet)workbook.Worksheets[1];//取得sheet1  
                //定义表格内数据的行数和列数   
                int rowscount = dataGridView.Rows.Count;
                int colscount = dataGridView.Columns.Count;


                //计算progressbar的长度
                pb_show.Maximum = rowscount * colscount;
                pb_show.Value = 0;


                //行数不可以大于65536   
                if (rowscount > 65536)
                {
                    MessageBox.Show("数据行记录超过65536行，不能保存！", "系统提示 ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    return;
                }
                //列数不可以大于255   
                if (colscount > 256)
                {
                    MessageBox.Show("数据列记录超过256列，不能保存！", "系统提示 ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    return;
                }
                //写入标题
                for (int i = 0; i < dataGridView.ColumnCount; i++)
                {
                    worksheet.Cells[1, i + 1] = dataGridView.Columns[i].HeaderText;
                }
                //写入数值
                for (int r = 0; r < dataGridView.Rows.Count; r++)
                {
                    for (int i = 0; i < dataGridView.ColumnCount; i++)
                    {
                        if (dataGridView[i, r].ValueType == typeof(string))
                        {
                            worksheet.Cells[r + 2, i + 1] = "" + dataGridView.Rows[r].Cells[i].Value;//将长数值转换成文本
                        }
                        else
                        {
                            worksheet.Cells[r + 2, i + 1] = dataGridView.Rows[r].Cells[i].Value;
                        }
                        pb_show.Value++;
                    }
                    System.Windows.Forms.Application.DoEvents();
                }
                worksheet.Columns.EntireColumn.AutoFit();//列宽自适应
                if (savedialog.FileName != "")
                {
                    try
                    {
                        workbook.Saved = true;
                        workbook.SaveCopyAs(savedialog.FileName);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show("导出文件时出错,文件可能正被打开！..." + ex.Message, "系统提示 ", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }

                }
                //GC.Collect();//强行销毁  
                MessageBox.Show("数据导出成功！ ", "提示信息", MessageBoxButtons.OK, MessageBoxIcon.Information);
                //关闭excel进程
                if (xlapp != null)
                {
                    xlapp.Quit();
                    System.Runtime.InteropServices.Marshal.ReleaseComObject(xlapp);
                    foreach (System.Diagnostics.Process theProc in System.Diagnostics.Process.GetProcessesByName("EXCEL"))
                    {
                        //先关闭图形窗口。如果关闭失败...有的时候在状态里看不到图形窗口的excel了，  
                        //但是在进程里仍然有EXCEL.EXE的进程存在，那么就需要杀掉它:p  
                        if (theProc.CloseMainWindow() == false)
                        {
                            theProc.Kill();
                        }
                    }
                    xlapp = null;
                }
            }
        }
    }
}
