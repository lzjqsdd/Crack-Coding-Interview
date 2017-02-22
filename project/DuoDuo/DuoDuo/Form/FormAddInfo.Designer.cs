namespace DuoDuo
{
    partial class FormAddInfo
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormAddInfo));
            this.label_UseDate = new System.Windows.Forms.Label();
            this.label_Number = new System.Windows.Forms.Label();
            this.label_Type = new System.Windows.Forms.Label();
            this.label_Reason = new System.Windows.Forms.Label();
            this.label_User = new System.Windows.Forms.Label();
            this.label_ReturnDate = new System.Windows.Forms.Label();
            this.label_ReturnPerson = new System.Windows.Forms.Label();
            this.dateTimePicker_UseDate = new System.Windows.Forms.DateTimePicker();
            this.textBox_Number = new System.Windows.Forms.TextBox();
            this.radioButton_type1 = new System.Windows.Forms.RadioButton();
            this.radioButton_type2 = new System.Windows.Forms.RadioButton();
            this.textBox_Reason = new System.Windows.Forms.TextBox();
            this.dateTimePicker_ReturnDate = new System.Windows.Forms.DateTimePicker();
            this.button_save = new System.Windows.Forms.Button();
            this.comboBox_user = new System.Windows.Forms.ComboBox();
            this.comboBox_ReturnPerson = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // label_UseDate
            // 
            this.label_UseDate.AutoSize = true;
            this.label_UseDate.Location = new System.Drawing.Point(14, 39);
            this.label_UseDate.Name = "label_UseDate";
            this.label_UseDate.Size = new System.Drawing.Size(56, 17);
            this.label_UseDate.TabIndex = 0;
            this.label_UseDate.Text = "使用日期";
            // 
            // label_Number
            // 
            this.label_Number.AutoSize = true;
            this.label_Number.Location = new System.Drawing.Point(14, 86);
            this.label_Number.Name = "label_Number";
            this.label_Number.Size = new System.Drawing.Size(32, 17);
            this.label_Number.TabIndex = 1;
            this.label_Number.Text = "金额";
            // 
            // label_Type
            // 
            this.label_Type.AutoSize = true;
            this.label_Type.Location = new System.Drawing.Point(14, 133);
            this.label_Type.Name = "label_Type";
            this.label_Type.Size = new System.Drawing.Size(32, 17);
            this.label_Type.TabIndex = 2;
            this.label_Type.Text = "类型";
            // 
            // label_Reason
            // 
            this.label_Reason.AutoSize = true;
            this.label_Reason.Location = new System.Drawing.Point(14, 180);
            this.label_Reason.Name = "label_Reason";
            this.label_Reason.Size = new System.Drawing.Size(32, 17);
            this.label_Reason.TabIndex = 3;
            this.label_Reason.Text = "用途";
            // 
            // label_User
            // 
            this.label_User.AutoSize = true;
            this.label_User.Location = new System.Drawing.Point(14, 227);
            this.label_User.Name = "label_User";
            this.label_User.Size = new System.Drawing.Size(44, 17);
            this.label_User.TabIndex = 4;
            this.label_User.Text = "用款人";
            // 
            // label_ReturnDate
            // 
            this.label_ReturnDate.AutoSize = true;
            this.label_ReturnDate.Location = new System.Drawing.Point(14, 274);
            this.label_ReturnDate.Name = "label_ReturnDate";
            this.label_ReturnDate.Size = new System.Drawing.Size(56, 17);
            this.label_ReturnDate.TabIndex = 5;
            this.label_ReturnDate.Text = "还款日期";
            // 
            // label_ReturnPerson
            // 
            this.label_ReturnPerson.AutoSize = true;
            this.label_ReturnPerson.Location = new System.Drawing.Point(14, 321);
            this.label_ReturnPerson.Name = "label_ReturnPerson";
            this.label_ReturnPerson.Size = new System.Drawing.Size(44, 17);
            this.label_ReturnPerson.TabIndex = 6;
            this.label_ReturnPerson.Text = "还款人";
            // 
            // dateTimePicker_UseDate
            // 
            this.dateTimePicker_UseDate.CustomFormat = "yyyy-MM-dd";
            this.dateTimePicker_UseDate.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dateTimePicker_UseDate.Location = new System.Drawing.Point(117, 33);
            this.dateTimePicker_UseDate.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.dateTimePicker_UseDate.Name = "dateTimePicker_UseDate";
            this.dateTimePicker_UseDate.Size = new System.Drawing.Size(135, 23);
            this.dateTimePicker_UseDate.TabIndex = 7;
            this.dateTimePicker_UseDate.Value = new System.DateTime(2016, 3, 31, 22, 11, 33, 0);
            // 
            // textBox_Number
            // 
            this.textBox_Number.Location = new System.Drawing.Point(117, 82);
            this.textBox_Number.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.textBox_Number.Name = "textBox_Number";
            this.textBox_Number.Size = new System.Drawing.Size(135, 23);
            this.textBox_Number.TabIndex = 8;
            this.textBox_Number.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.money_onKeyPress);
            // 
            // radioButton_type1
            // 
            this.radioButton_type1.AutoSize = true;
            this.radioButton_type1.Location = new System.Drawing.Point(117, 129);
            this.radioButton_type1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.radioButton_type1.Name = "radioButton_type1";
            this.radioButton_type1.Size = new System.Drawing.Size(50, 21);
            this.radioButton_type1.TabIndex = 11;
            this.radioButton_type1.TabStop = true;
            this.radioButton_type1.Text = "收入";
            this.radioButton_type1.UseVisualStyleBackColor = true;
            // 
            // radioButton_type2
            // 
            this.radioButton_type2.AutoSize = true;
            this.radioButton_type2.Location = new System.Drawing.Point(202, 129);
            this.radioButton_type2.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.radioButton_type2.Name = "radioButton_type2";
            this.radioButton_type2.Size = new System.Drawing.Size(50, 21);
            this.radioButton_type2.TabIndex = 12;
            this.radioButton_type2.TabStop = true;
            this.radioButton_type2.Text = "支出";
            this.radioButton_type2.UseVisualStyleBackColor = true;
            // 
            // textBox_Reason
            // 
            this.textBox_Reason.Location = new System.Drawing.Point(117, 174);
            this.textBox_Reason.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.textBox_Reason.Name = "textBox_Reason";
            this.textBox_Reason.Size = new System.Drawing.Size(135, 23);
            this.textBox_Reason.TabIndex = 13;
            // 
            // dateTimePicker_ReturnDate
            // 
            this.dateTimePicker_ReturnDate.Location = new System.Drawing.Point(117, 269);
            this.dateTimePicker_ReturnDate.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.dateTimePicker_ReturnDate.Name = "dateTimePicker_ReturnDate";
            this.dateTimePicker_ReturnDate.Size = new System.Drawing.Size(135, 23);
            this.dateTimePicker_ReturnDate.TabIndex = 16;
            // 
            // button_save
            // 
            this.button_save.Image = ((System.Drawing.Image)(resources.GetObject("button_save.Image")));
            this.button_save.Location = new System.Drawing.Point(86, 381);
            this.button_save.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button_save.Name = "button_save";
            this.button_save.Size = new System.Drawing.Size(127, 44);
            this.button_save.TabIndex = 17;
            this.button_save.Text = "保存";
            this.button_save.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.button_save.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageBeforeText;
            this.button_save.UseVisualStyleBackColor = true;
            this.button_save.Click += new System.EventHandler(this.button_save_Click);
            // 
            // comboBox_user
            // 
            this.comboBox_user.FormattingEnabled = true;
            this.comboBox_user.Location = new System.Drawing.Point(117, 219);
            this.comboBox_user.Name = "comboBox_user";
            this.comboBox_user.Size = new System.Drawing.Size(135, 25);
            this.comboBox_user.TabIndex = 18;
            this.comboBox_user.Text = "杨月";
            // 
            // comboBox_ReturnPerson
            // 
            this.comboBox_ReturnPerson.FormattingEnabled = true;
            this.comboBox_ReturnPerson.Location = new System.Drawing.Point(117, 321);
            this.comboBox_ReturnPerson.Name = "comboBox_ReturnPerson";
            this.comboBox_ReturnPerson.Size = new System.Drawing.Size(135, 25);
            this.comboBox_ReturnPerson.TabIndex = 19;
            this.comboBox_ReturnPerson.Text = "杨月";
            // 
            // FormAddInfo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 17F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(278, 448);
            this.Controls.Add(this.comboBox_ReturnPerson);
            this.Controls.Add(this.comboBox_user);
            this.Controls.Add(this.button_save);
            this.Controls.Add(this.dateTimePicker_ReturnDate);
            this.Controls.Add(this.textBox_Reason);
            this.Controls.Add(this.radioButton_type2);
            this.Controls.Add(this.radioButton_type1);
            this.Controls.Add(this.textBox_Number);
            this.Controls.Add(this.dateTimePicker_UseDate);
            this.Controls.Add(this.label_ReturnPerson);
            this.Controls.Add(this.label_ReturnDate);
            this.Controls.Add(this.label_User);
            this.Controls.Add(this.label_Reason);
            this.Controls.Add(this.label_Type);
            this.Controls.Add(this.label_Number);
            this.Controls.Add(this.label_UseDate);
            this.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.MaximizeBox = false;
            this.Name = "FormAddInfo";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "新增款项";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label_UseDate;
        private System.Windows.Forms.Label label_Number;
        private System.Windows.Forms.Label label_Type;
        private System.Windows.Forms.Label label_Reason;
        private System.Windows.Forms.Label label_User;
        private System.Windows.Forms.Label label_ReturnDate;
        private System.Windows.Forms.Label label_ReturnPerson;
        private System.Windows.Forms.DateTimePicker dateTimePicker_UseDate;
        private System.Windows.Forms.TextBox textBox_Number;
        private System.Windows.Forms.RadioButton radioButton_type1;
        private System.Windows.Forms.RadioButton radioButton_type2;
        private System.Windows.Forms.TextBox textBox_Reason;
        private System.Windows.Forms.DateTimePicker dateTimePicker_ReturnDate;
        private System.Windows.Forms.Button button_save;
        private System.Windows.Forms.ComboBox comboBox_user;
        private System.Windows.Forms.ComboBox comboBox_ReturnPerson;
    }
}