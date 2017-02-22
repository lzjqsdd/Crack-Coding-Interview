namespace DuoDuo
{
    partial class Form_Account
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.Button button_AddPublicBill;
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form_Account));
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.button_export = new System.Windows.Forms.Button();
            this.button_sta = new System.Windows.Forms.Button();
            this.button_user = new System.Windows.Forms.Button();
            this.button_settings = new System.Windows.Forms.Button();
            this.groupBox_IndirectBill = new System.Windows.Forms.GroupBox();
            this.button_AddIndirectBill = new System.Windows.Forms.Button();
            this.groupBox_PublicCard = new System.Windows.Forms.GroupBox();
            this.button_AddPublicCard = new System.Windows.Forms.Button();
            this.groupBox_PublicBill = new System.Windows.Forms.GroupBox();
            this.button_CheckBill = new System.Windows.Forms.Button();
            this.checkBox_all = new System.Windows.Forms.CheckBox();
            this.progressBar_show = new System.Windows.Forms.ProgressBar();
            this.button_search = new System.Windows.Forms.Button();
            this.comboBox_table = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.dateTimePicker_etime = new System.Windows.Forms.DateTimePicker();
            this.dateTimePicker_stime = new System.Windows.Forms.DateTimePicker();
            this.dataGridView_Account = new System.Windows.Forms.DataGridView();
            this.contextMenuStrip_export = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.toolStripMenuItem_public_bill = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem_public_card = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem_indirect_bill = new System.Windows.Forms.ToolStripMenuItem();
            this.ToolStripMenuItem_CurrentData = new System.Windows.Forms.ToolStripMenuItem();
            button_AddPublicBill = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox_IndirectBill.SuspendLayout();
            this.groupBox_PublicCard.SuspendLayout();
            this.groupBox_PublicBill.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_Account)).BeginInit();
            this.contextMenuStrip_export.SuspendLayout();
            this.SuspendLayout();
            // 
            // button_AddPublicBill
            // 
            button_AddPublicBill.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            button_AddPublicBill.Image = global::DuoDuo.Properties.Resources._1459499823_file_edit;
            button_AddPublicBill.Location = new System.Drawing.Point(75, 34);
            button_AddPublicBill.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            button_AddPublicBill.Name = "button_AddPublicBill";
            button_AddPublicBill.Size = new System.Drawing.Size(126, 58);
            button_AddPublicBill.TabIndex = 0;
            button_AddPublicBill.Text = "新增款项";
            button_AddPublicBill.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            button_AddPublicBill.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            button_AddPublicBill.UseVisualStyleBackColor = true;
            button_AddPublicBill.Click += new System.EventHandler(this.button_AddPublicBill_Click);
            // 
            // splitContainer1
            // 
            this.splitContainer1.BackColor = System.Drawing.Color.Teal;
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.IsSplitterFixed = true;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.BackColor = System.Drawing.SystemColors.Window;
            this.splitContainer1.Panel1.Controls.Add(this.groupBox1);
            this.splitContainer1.Panel1.Controls.Add(this.groupBox_IndirectBill);
            this.splitContainer1.Panel1.Controls.Add(this.groupBox_PublicCard);
            this.splitContainer1.Panel1.Controls.Add(this.groupBox_PublicBill);
            this.splitContainer1.Panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.splitContainer1_Panel1_Paint);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.BackColor = System.Drawing.SystemColors.Window;
            this.splitContainer1.Panel2.Controls.Add(this.checkBox_all);
            this.splitContainer1.Panel2.Controls.Add(this.progressBar_show);
            this.splitContainer1.Panel2.Controls.Add(this.button_search);
            this.splitContainer1.Panel2.Controls.Add(this.comboBox_table);
            this.splitContainer1.Panel2.Controls.Add(this.label1);
            this.splitContainer1.Panel2.Controls.Add(this.dateTimePicker_etime);
            this.splitContainer1.Panel2.Controls.Add(this.dateTimePicker_stime);
            this.splitContainer1.Panel2.Controls.Add(this.dataGridView_Account);
            this.splitContainer1.Size = new System.Drawing.Size(1088, 643);
            this.splitContainer1.SplitterDistance = 309;
            this.splitContainer1.SplitterWidth = 2;
            this.splitContainer1.TabIndex = 0;
            this.splitContainer1.SplitterMoved += new System.Windows.Forms.SplitterEventHandler(this.splitContainer1_SplitterMoved);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.button_export);
            this.groupBox1.Controls.Add(this.button_sta);
            this.groupBox1.Controls.Add(this.button_user);
            this.groupBox1.Controls.Add(this.button_settings);
            this.groupBox1.Font = new System.Drawing.Font("微软雅黑", 10F);
            this.groupBox1.Location = new System.Drawing.Point(14, 464);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.groupBox1.Size = new System.Drawing.Size(272, 172);
            this.groupBox1.TabIndex = 4;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "其他";
            // 
            // button_export
            // 
            this.button_export.BackColor = System.Drawing.SystemColors.Window;
            this.button_export.FlatAppearance.BorderColor = System.Drawing.SystemColors.Window;
            this.button_export.FlatAppearance.MouseDownBackColor = System.Drawing.Color.SkyBlue;
            this.button_export.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button_export.Image = global::DuoDuo.Properties.Resources._1459507464_document_export;
            this.button_export.Location = new System.Drawing.Point(155, 107);
            this.button_export.Name = "button_export";
            this.button_export.Size = new System.Drawing.Size(85, 43);
            this.button_export.TabIndex = 9;
            this.button_export.Text = "导出";
            this.button_export.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.button_export.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.button_export.UseVisualStyleBackColor = false;
            this.button_export.Click += new System.EventHandler(this.button_export_Click);
            // 
            // button_sta
            // 
            this.button_sta.BackColor = System.Drawing.SystemColors.Window;
            this.button_sta.FlatAppearance.BorderColor = System.Drawing.SystemColors.Window;
            this.button_sta.FlatAppearance.MouseDownBackColor = System.Drawing.Color.SkyBlue;
            this.button_sta.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button_sta.Image = global::DuoDuo.Properties.Resources._1459499837_piechart;
            this.button_sta.Location = new System.Drawing.Point(155, 34);
            this.button_sta.Name = "button_sta";
            this.button_sta.Size = new System.Drawing.Size(85, 43);
            this.button_sta.TabIndex = 8;
            this.button_sta.Text = "统计";
            this.button_sta.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.button_sta.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.button_sta.UseVisualStyleBackColor = false;
            this.button_sta.Click += new System.EventHandler(this.button_sta_Click);
            // 
            // button_user
            // 
            this.button_user.BackColor = System.Drawing.SystemColors.Window;
            this.button_user.FlatAppearance.BorderColor = System.Drawing.SystemColors.Window;
            this.button_user.FlatAppearance.MouseDownBackColor = System.Drawing.Color.SkyBlue;
            this.button_user.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button_user.Image = global::DuoDuo.Properties.Resources._1459499854_user_add;
            this.button_user.Location = new System.Drawing.Point(24, 107);
            this.button_user.Name = "button_user";
            this.button_user.Size = new System.Drawing.Size(85, 43);
            this.button_user.TabIndex = 7;
            this.button_user.Text = "用户";
            this.button_user.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.button_user.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.button_user.UseVisualStyleBackColor = false;
            this.button_user.Click += new System.EventHandler(this.button_user_Click);
            // 
            // button_settings
            // 
            this.button_settings.BackColor = System.Drawing.SystemColors.Window;
            this.button_settings.FlatAppearance.BorderColor = System.Drawing.SystemColors.Window;
            this.button_settings.FlatAppearance.MouseDownBackColor = System.Drawing.Color.SkyBlue;
            this.button_settings.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button_settings.Image = global::DuoDuo.Properties.Resources._1459453676_advancedsettings;
            this.button_settings.Location = new System.Drawing.Point(24, 34);
            this.button_settings.Name = "button_settings";
            this.button_settings.Size = new System.Drawing.Size(85, 43);
            this.button_settings.TabIndex = 6;
            this.button_settings.Text = "设置";
            this.button_settings.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.button_settings.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.button_settings.UseVisualStyleBackColor = false;
            this.button_settings.Click += new System.EventHandler(this.button_settings_Click);
            // 
            // groupBox_IndirectBill
            // 
            this.groupBox_IndirectBill.Controls.Add(this.button_AddIndirectBill);
            this.groupBox_IndirectBill.Font = new System.Drawing.Font("微软雅黑", 10F);
            this.groupBox_IndirectBill.Location = new System.Drawing.Point(14, 338);
            this.groupBox_IndirectBill.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.groupBox_IndirectBill.Name = "groupBox_IndirectBill";
            this.groupBox_IndirectBill.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.groupBox_IndirectBill.Size = new System.Drawing.Size(272, 118);
            this.groupBox_IndirectBill.TabIndex = 1;
            this.groupBox_IndirectBill.TabStop = false;
            this.groupBox_IndirectBill.Text = "间接经费";
            // 
            // button_AddIndirectBill
            // 
            this.button_AddIndirectBill.Image = global::DuoDuo.Properties.Resources._1459499823_file_edit;
            this.button_AddIndirectBill.Location = new System.Drawing.Point(75, 38);
            this.button_AddIndirectBill.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button_AddIndirectBill.Name = "button_AddIndirectBill";
            this.button_AddIndirectBill.Size = new System.Drawing.Size(126, 58);
            this.button_AddIndirectBill.TabIndex = 3;
            this.button_AddIndirectBill.Text = "新增款项";
            this.button_AddIndirectBill.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.button_AddIndirectBill.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.button_AddIndirectBill.UseVisualStyleBackColor = true;
            this.button_AddIndirectBill.Click += new System.EventHandler(this.button_AddIndirectBill_Click);
            // 
            // groupBox_PublicCard
            // 
            this.groupBox_PublicCard.Controls.Add(this.button_AddPublicCard);
            this.groupBox_PublicCard.Font = new System.Drawing.Font("微软雅黑", 10F);
            this.groupBox_PublicCard.Location = new System.Drawing.Point(14, 226);
            this.groupBox_PublicCard.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.groupBox_PublicCard.Name = "groupBox_PublicCard";
            this.groupBox_PublicCard.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.groupBox_PublicCard.Size = new System.Drawing.Size(272, 104);
            this.groupBox_PublicCard.TabIndex = 1;
            this.groupBox_PublicCard.TabStop = false;
            this.groupBox_PublicCard.Text = "公务卡";
            // 
            // button_AddPublicCard
            // 
            this.button_AddPublicCard.Image = global::DuoDuo.Properties.Resources._1459499823_file_edit;
            this.button_AddPublicCard.Location = new System.Drawing.Point(75, 26);
            this.button_AddPublicCard.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button_AddPublicCard.Name = "button_AddPublicCard";
            this.button_AddPublicCard.Size = new System.Drawing.Size(126, 58);
            this.button_AddPublicCard.TabIndex = 2;
            this.button_AddPublicCard.Text = "新增款项";
            this.button_AddPublicCard.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.button_AddPublicCard.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.button_AddPublicCard.UseVisualStyleBackColor = true;
            this.button_AddPublicCard.Click += new System.EventHandler(this.button_AddPublicCard_Click);
            // 
            // groupBox_PublicBill
            // 
            this.groupBox_PublicBill.Controls.Add(this.button_CheckBill);
            this.groupBox_PublicBill.Controls.Add(button_AddPublicBill);
            this.groupBox_PublicBill.Font = new System.Drawing.Font("微软雅黑", 10F);
            this.groupBox_PublicBill.Location = new System.Drawing.Point(14, 17);
            this.groupBox_PublicBill.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.groupBox_PublicBill.Name = "groupBox_PublicBill";
            this.groupBox_PublicBill.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.groupBox_PublicBill.Size = new System.Drawing.Size(272, 201);
            this.groupBox_PublicBill.TabIndex = 0;
            this.groupBox_PublicBill.TabStop = false;
            this.groupBox_PublicBill.Text = "公共经费";
            // 
            // button_CheckBill
            // 
            this.button_CheckBill.Image = global::DuoDuo.Properties.Resources._1459499649_analysis;
            this.button_CheckBill.Location = new System.Drawing.Point(75, 124);
            this.button_CheckBill.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button_CheckBill.Name = "button_CheckBill";
            this.button_CheckBill.Size = new System.Drawing.Size(126, 58);
            this.button_CheckBill.TabIndex = 1;
            this.button_CheckBill.Text = "对账";
            this.button_CheckBill.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.button_CheckBill.UseVisualStyleBackColor = true;
            this.button_CheckBill.Click += new System.EventHandler(this.button_CheckBill_Click);
            // 
            // checkBox_all
            // 
            this.checkBox_all.AutoSize = true;
            this.checkBox_all.Location = new System.Drawing.Point(445, 19);
            this.checkBox_all.Name = "checkBox_all";
            this.checkBox_all.Size = new System.Drawing.Size(99, 21);
            this.checkBox_all.TabIndex = 7;
            this.checkBox_all.Text = "显示所有数据";
            this.checkBox_all.UseVisualStyleBackColor = true;
            // 
            // progressBar_show
            // 
            this.progressBar_show.Location = new System.Drawing.Point(3, 613);
            this.progressBar_show.Name = "progressBar_show";
            this.progressBar_show.Size = new System.Drawing.Size(765, 27);
            this.progressBar_show.TabIndex = 6;
            // 
            // button_search
            // 
            this.button_search.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.button_search.Image = global::DuoDuo.Properties.Resources._1459499771_file_search;
            this.button_search.Location = new System.Drawing.Point(561, 7);
            this.button_search.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button_search.Name = "button_search";
            this.button_search.Size = new System.Drawing.Size(89, 42);
            this.button_search.TabIndex = 5;
            this.button_search.Text = "查询";
            this.button_search.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.button_search.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.button_search.UseVisualStyleBackColor = true;
            this.button_search.Click += new System.EventHandler(this.button_search_Click);
            // 
            // comboBox_table
            // 
            this.comboBox_table.FormattingEnabled = true;
            this.comboBox_table.Items.AddRange(new object[] {
            "公共经费",
            "公务卡",
            "间接经费"});
            this.comboBox_table.Location = new System.Drawing.Point(287, 18);
            this.comboBox_table.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.comboBox_table.Name = "comboBox_table";
            this.comboBox_table.Size = new System.Drawing.Size(152, 25);
            this.comboBox_table.TabIndex = 4;
            this.comboBox_table.Text = "公共经费";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(128, 25);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(20, 17);
            this.label1.TabIndex = 3;
            this.label1.Text = "到";
            // 
            // dateTimePicker_etime
            // 
            this.dateTimePicker_etime.Location = new System.Drawing.Point(154, 20);
            this.dateTimePicker_etime.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.dateTimePicker_etime.Name = "dateTimePicker_etime";
            this.dateTimePicker_etime.Size = new System.Drawing.Size(117, 23);
            this.dateTimePicker_etime.TabIndex = 2;
            // 
            // dateTimePicker_stime
            // 
            this.dateTimePicker_stime.CustomFormat = "YYYY/MM/DD";
            this.dateTimePicker_stime.Location = new System.Drawing.Point(3, 20);
            this.dateTimePicker_stime.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.dateTimePicker_stime.Name = "dateTimePicker_stime";
            this.dateTimePicker_stime.Size = new System.Drawing.Size(119, 23);
            this.dateTimePicker_stime.TabIndex = 1;
            // 
            // dataGridView_Account
            // 
            this.dataGridView_Account.BackgroundColor = System.Drawing.Color.GhostWhite;
            this.dataGridView_Account.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView_Account.GridColor = System.Drawing.Color.LightSkyBlue;
            this.dataGridView_Account.Location = new System.Drawing.Point(3, 51);
            this.dataGridView_Account.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.dataGridView_Account.Name = "dataGridView_Account";
            this.dataGridView_Account.RowTemplate.Height = 23;
            this.dataGridView_Account.Size = new System.Drawing.Size(765, 563);
            this.dataGridView_Account.TabIndex = 0;
            this.dataGridView_Account.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView_Account_CellContentClick);
            // 
            // contextMenuStrip_export
            // 
            this.contextMenuStrip_export.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem_public_bill,
            this.toolStripMenuItem_public_card,
            this.toolStripMenuItem_indirect_bill,
            this.ToolStripMenuItem_CurrentData});
            this.contextMenuStrip_export.Name = "contextMenuStrip_export";
            this.contextMenuStrip_export.Size = new System.Drawing.Size(168, 92);
            // 
            // toolStripMenuItem_public_bill
            // 
            this.toolStripMenuItem_public_bill.Name = "toolStripMenuItem_public_bill";
            this.toolStripMenuItem_public_bill.Size = new System.Drawing.Size(167, 22);
            this.toolStripMenuItem_public_bill.Text = "导出-->公共经费";
            this.toolStripMenuItem_public_bill.Click += new System.EventHandler(this.toolStripMenuItem_public_bill_Click);
            // 
            // toolStripMenuItem_public_card
            // 
            this.toolStripMenuItem_public_card.Name = "toolStripMenuItem_public_card";
            this.toolStripMenuItem_public_card.Size = new System.Drawing.Size(167, 22);
            this.toolStripMenuItem_public_card.Text = "导出-->公务卡";
            this.toolStripMenuItem_public_card.Click += new System.EventHandler(this.toolStripMenuItem_public_card_Click);
            // 
            // toolStripMenuItem_indirect_bill
            // 
            this.toolStripMenuItem_indirect_bill.Name = "toolStripMenuItem_indirect_bill";
            this.toolStripMenuItem_indirect_bill.Size = new System.Drawing.Size(167, 22);
            this.toolStripMenuItem_indirect_bill.Text = "导出-->间接经费";
            this.toolStripMenuItem_indirect_bill.Click += new System.EventHandler(this.toolStripMenuItem_indirect_bill_Click);
            // 
            // ToolStripMenuItem_CurrentData
            // 
            this.ToolStripMenuItem_CurrentData.Name = "ToolStripMenuItem_CurrentData";
            this.ToolStripMenuItem_CurrentData.Size = new System.Drawing.Size(167, 22);
            this.ToolStripMenuItem_CurrentData.Text = "导出-->表格数据";
            this.ToolStripMenuItem_CurrentData.Click += new System.EventHandler(this.ToolStripMenuItem_CurrentData_Click);
            // 
            // Form_Account
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 17F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.ClientSize = new System.Drawing.Size(1088, 643);
            this.Controls.Add(this.splitContainer1);
            this.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.MaximizeBox = false;
            this.Name = "Form_Account";
            this.Text = "多多记账";
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox_IndirectBill.ResumeLayout(false);
            this.groupBox_PublicCard.ResumeLayout(false);
            this.groupBox_PublicBill.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_Account)).EndInit();
            this.contextMenuStrip_export.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.GroupBox groupBox_PublicBill;
        private System.Windows.Forms.DataGridView dataGridView_Account;
        private System.Windows.Forms.GroupBox groupBox_IndirectBill;
        private System.Windows.Forms.GroupBox groupBox_PublicCard;
        private System.Windows.Forms.DateTimePicker dateTimePicker_stime;
        private System.Windows.Forms.DateTimePicker dateTimePicker_etime;
        private System.Windows.Forms.Button button_AddIndirectBill;
        private System.Windows.Forms.Button button_AddPublicCard;
        private System.Windows.Forms.Button button_CheckBill;
        private System.Windows.Forms.Button button_search;
        private System.Windows.Forms.ComboBox comboBox_table;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button_settings;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button button_user;
        private System.Windows.Forms.Button button_sta;
        private System.Windows.Forms.Button button_export;
        private System.Windows.Forms.ProgressBar progressBar_show;
        private System.Windows.Forms.CheckBox checkBox_all;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip_export;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem_public_bill;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem_public_card;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem_indirect_bill;
        private System.Windows.Forms.ToolStripMenuItem ToolStripMenuItem_CurrentData;
    }
}

