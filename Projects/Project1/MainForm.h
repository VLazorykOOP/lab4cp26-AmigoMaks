#pragma once

#include "AddForm.h"
#include "OrderForm.h"

namespace Project1 {

	using namespace MySql::Data::MySqlClient;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	
		void ShowAllFurniture() {
			String^ connString = "Server=localhost;Database=FurnitureDB;Uid=root;Pwd=pmpm2424;";
			MySqlConnection^ conn = gcnew MySqlConnection(connString);
			\
			String^ sql = "SELECT f.id_furniture AS 'ID', f.type AS 'Type', f.brand AS 'Brand', " +
				"m.material_name AS 'Material', s.name AS 'Supplier', f.final_price AS 'Price' " +
				"FROM Furniture f " +
				"JOIN Materials m ON f.id_material = m.id_material " +
				"JOIN Suppliers s ON f.id_supplier = s.id_supplier";

			try {
				MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(sql, conn);
				DataTable^ dbDataSet = gcnew DataTable();

				conn->Open();
				adapter->Fill(dbDataSet);

				GridFurniture->DataSource = dbDataSet;

				GridFurniture->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			}
			catch (Exception^ ex) {
				MessageBox::Show("Loading error: " + ex->Message);
			}
			finally {
				conn->Close();
			}
		}

		void RefreshGrid() {
			String^ connString = "Server=localhost;Database=FurnitureDB;Uid=root;Pwd=pmpm2424;";
			MySqlConnection^ conn = gcnew MySqlConnection(connString);

			String^ query = "SELECT id_furniture AS 'ID', type AS 'Type', brand AS 'Brand', " +
				"material AS 'Material', supplier AS 'Supplier', price AS 'Price' " +
				"FROM furniture_table";

			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(query, conn);
			DataTable^ dt = gcnew DataTable();

			try {
				conn->Open();
				adapter->Fill(dt);
				GridFurniture->DataSource = dt;
			}
			catch (Exception^ ex) {
				MessageBox::Show("DB Error: " + ex->Message);
			}
			finally {
				conn->Close();
			}
		}
	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ GridFurniture;







	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtSearch;

	private: System::Windows::Forms::Button^ button1;





	private: System::Windows::Forms::Button^ btnAddFurniture;

	private: System::Windows::Forms::Button^ btnCreateOrder;





	protected:



	protected:

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
			this->GridFurniture = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnAddFurniture = (gcnew System::Windows::Forms::Button());
			this->btnCreateOrder = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridFurniture))->BeginInit();
			this->SuspendLayout();
			// 
			// GridFurniture
			// 
			this->GridFurniture->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->GridFurniture->Location = System::Drawing::Point(-2, 41);
			this->GridFurniture->Name = L"GridFurniture";
			this->GridFurniture->RowHeadersWidth = 51;
			this->GridFurniture->RowTemplate->Height = 24;
			this->GridFurniture->Size = System::Drawing::Size(984, 511);
			this->GridFurniture->TabIndex = 0;
			this->GridFurniture->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::GridFurniture_CellContentClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Search:";
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(159, 9);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(200, 22);
			this->txtSearch->TabIndex = 4;
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &MainForm::txtSearch_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(409, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Clear";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// btnAddFurniture
			// 
			this->btnAddFurniture->Location = System::Drawing::Point(638, 416);
			this->btnAddFurniture->Name = L"btnAddFurniture";
			this->btnAddFurniture->Size = System::Drawing::Size(135, 23);
			this->btnAddFurniture->TabIndex = 6;
			this->btnAddFurniture->Text = L"Add furniture";
			this->btnAddFurniture->UseVisualStyleBackColor = true;
			this->btnAddFurniture->Click += gcnew System::EventHandler(this, &MainForm::btnAddFurniture_Click);
			// 
			// btnCreateOrder
			// 
			this->btnCreateOrder->Location = System::Drawing::Point(118, 416);
			this->btnCreateOrder->Name = L"btnCreateOrder";
			this->btnCreateOrder->Size = System::Drawing::Size(135, 23);
			this->btnCreateOrder->TabIndex = 7;
			this->btnCreateOrder->Text = L"Make order";
			this->btnCreateOrder->UseVisualStyleBackColor = true;
			this->btnCreateOrder->Click += gcnew System::EventHandler(this, &MainForm::btnCreateOrder_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(981, 553);
			this->Controls->Add(this->btnCreateOrder);
			this->Controls->Add(this->btnAddFurniture);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->GridFurniture);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridFurniture))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GridFurniture_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
private: System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	ShowAllFurniture();
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ connString = "Server=localhost;Database=FurnitureDB;Uid=root;Pwd=pmpm2424;";
	MySqlConnection^ conn = gcnew MySqlConnection(connString);

	String^ sql = "SELECT f.id_furniture AS 'ID', f.type AS 'Type', f.brand AS 'Brand', " +
		"m.material_name AS 'Material', s.name AS 'Supplier', f.final_price AS 'Price' " +
		"FROM Furniture f " +
		"JOIN Materials m ON f.id_material = m.id_material " +
		"JOIN Suppliers s ON f.id_supplier = s.id_supplier " +
		"WHERE f.brand LIKE @filter OR f.type LIKE @filter";

	MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
	cmd->Parameters->AddWithValue("@filter", "%" + txtSearch->Text + "%");

	try {
		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
		DataTable^ dt = gcnew DataTable();
		adapter->Fill(dt);
		GridFurniture->DataSource = dt;
	}
	catch (Exception^ ex) {
		System::Diagnostics::Debug::WriteLine(ex->Message);
	}
	finally {
		conn->Close();
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	txtSearch->Text = "";
}
private: System::Void btnAddFurniture_Click(System::Object^ sender, System::EventArgs^ e) {
	Project1::AddForm^ addF = gcnew Project1::AddForm();

	if (addF->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		ShowAllFurniture();
	}
}
private: System::Void btnCreateOrder_Click(System::Object^ sender, System::EventArgs^ e) {
	Project1::OrderForm^ ordF = gcnew Project1::OrderForm();
	ordF->ShowDialog();
}
};
}
