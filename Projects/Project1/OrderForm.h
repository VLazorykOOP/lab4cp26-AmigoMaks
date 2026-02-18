#pragma once

namespace Project1 {

	using namespace MySql::Data::MySqlClient;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for OrderForm
	/// </summary>
	public ref class OrderForm : public System::Windows::Forms::Form
	{
	public:
		OrderForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void LoadFurnitureList() {
			String^ connString = "Server=localhost;Database=FurnitureDB;Uid=root;Pwd=pmpm2424;";
			MySqlConnection^ conn = gcnew MySqlConnection(connString);
			String^ sql = "SELECT id_furniture, CONCAT(type, ' ', brand, ' - ', final_price, ' hrn') AS info FROM Furniture";

			try {
				MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(sql, conn);
				DataTable^ dt = gcnew DataTable();
				adapter->Fill(dt);

				cmbFurniture->DataSource = dt;
				cmbFurniture->DisplayMember = "info";
				cmbFurniture->ValueMember = "id_furniture";
			}
			catch (Exception^ ex) { MessageBox::Show(ex->Message); }
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OrderForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cmbFurniture;
	private: System::Windows::Forms::TextBox^ txtCustomerPhone;
	private: System::Windows::Forms::TextBox^ txtCustomerName;
	private: System::Windows::Forms::Button^ btnConfirmOrder;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cmbFurniture = (gcnew System::Windows::Forms::ComboBox());
			this->txtCustomerPhone = (gcnew System::Windows::Forms::TextBox());
			this->txtCustomerName = (gcnew System::Windows::Forms::TextBox());
			this->btnConfirmOrder = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Choose furniture for order";
			this->label1->Click += gcnew System::EventHandler(this, &OrderForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(30, 137);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Your name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(30, 242);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Phone";
			// 
			// cmbFurniture
			// 
			this->cmbFurniture->FormattingEnabled = true;
			this->cmbFurniture->Location = System::Drawing::Point(331, 44);
			this->cmbFurniture->Name = L"cmbFurniture";
			this->cmbFurniture->Size = System::Drawing::Size(290, 24);
			this->cmbFurniture->TabIndex = 3;
			// 
			// txtCustomerPhone
			// 
			this->txtCustomerPhone->Location = System::Drawing::Point(331, 236);
			this->txtCustomerPhone->Name = L"txtCustomerPhone";
			this->txtCustomerPhone->Size = System::Drawing::Size(290, 22);
			this->txtCustomerPhone->TabIndex = 4;
			// 
			// txtCustomerName
			// 
			this->txtCustomerName->Location = System::Drawing::Point(331, 131);
			this->txtCustomerName->Name = L"txtCustomerName";
			this->txtCustomerName->Size = System::Drawing::Size(290, 22);
			this->txtCustomerName->TabIndex = 5;
			// 
			// btnConfirmOrder
			// 
			this->btnConfirmOrder->Location = System::Drawing::Point(204, 342);
			this->btnConfirmOrder->Name = L"btnConfirmOrder";
			this->btnConfirmOrder->Size = System::Drawing::Size(192, 23);
			this->btnConfirmOrder->TabIndex = 6;
			this->btnConfirmOrder->Text = L"Confirm order";
			this->btnConfirmOrder->UseVisualStyleBackColor = true;
			this->btnConfirmOrder->Click += gcnew System::EventHandler(this, &OrderForm::btnConfirmOrder_Click);
			// 
			// OrderForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(672, 470);
			this->Controls->Add(this->btnConfirmOrder);
			this->Controls->Add(this->txtCustomerName);
			this->Controls->Add(this->txtCustomerPhone);
			this->Controls->Add(this->cmbFurniture);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"OrderForm";
			this->Text = L"OrderForm";
			this->Load += gcnew System::EventHandler(this, &OrderForm::OrderForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void OrderForm_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadFurnitureList();
	}
private: System::Void btnConfirmOrder_Click(System::Object^ sender, System::EventArgs^ e) {
	if (txtCustomerName->Text == "" || txtCustomerPhone->Text == "") {
		MessageBox::Show("Please fill data");
		return;
	}

	String^ connString = "Server=localhost;Database=FurnitureDB;Uid=root;Pwd=pmpm2424;";
	MySqlConnection^ conn = gcnew MySqlConnection(connString);
	String^ sql = "INSERT INTO Orders (customer_name, customer_phone, id_furniture) VALUES (@name, @phone, @id)";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
	cmd->Parameters->AddWithValue("@name", txtCustomerName->Text);
	cmd->Parameters->AddWithValue("@phone", txtCustomerPhone->Text);
	cmd->Parameters->AddWithValue("@id", cmbFurniture->SelectedValue);

	try {
		conn->Open();
		cmd->ExecuteNonQuery();
		MessageBox::Show("Thanks! Your order was accepted", "Success");
		this->Close();
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}
	finally {
		conn->Close();
	}
}
};
}
