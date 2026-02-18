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
	/// Summary for AddEditForm
	/// </summary>
	public ref class AddForm : public System::Windows::Forms::Form
	{
	public:
		AddForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void FillComboBoxes() {
			String^ connString = "Server=localhost;Database=FurnitureDB;Uid=root;Pwd=pmpm2424;";
			MySqlConnection^ conn = gcnew MySqlConnection(connString);

			try {
				conn->Open();

				MySqlDataAdapter^ matAdapter = gcnew MySqlDataAdapter("SELECT id_material, material_name FROM Materials", conn);
				DataTable^ matTable = gcnew DataTable();
				matAdapter->Fill(matTable);
				cmbMaterial->DataSource = matTable;
				cmbMaterial->DisplayMember = "material_name";
				cmbMaterial->ValueMember = "id_material";

				MySqlDataAdapter^ supAdapter = gcnew MySqlDataAdapter("SELECT id_supplier, name FROM Suppliers", conn);
				DataTable^ supTable = gcnew DataTable();
				supAdapter->Fill(supTable);
				cmbSupplier->DataSource = supTable;
				cmbSupplier->DisplayMember = "name"; 
				cmbSupplier->ValueMember = "id_supplier"; 
			}
			catch (Exception^ ex) {
				MessageBox::Show("List load error: " + ex->Message);
			}
			finally {
				conn->Close();
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ cmbMaterial;
	protected:

	private: System::Windows::Forms::TextBox^ txtBrand;
	private: System::Windows::Forms::TextBox^ txtType;
	private: System::Windows::Forms::TextBox^ txtPrice;
	private: System::Windows::Forms::ComboBox^ cmbSupplier;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;




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
			this->cmbMaterial = (gcnew System::Windows::Forms::ComboBox());
			this->txtBrand = (gcnew System::Windows::Forms::TextBox());
			this->txtType = (gcnew System::Windows::Forms::TextBox());
			this->txtPrice = (gcnew System::Windows::Forms::TextBox());
			this->cmbSupplier = (gcnew System::Windows::Forms::ComboBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// cmbMaterial
			// 
			this->cmbMaterial->FormattingEnabled = true;
			this->cmbMaterial->Location = System::Drawing::Point(472, 86);
			this->cmbMaterial->Name = L"cmbMaterial";
			this->cmbMaterial->Size = System::Drawing::Size(121, 24);
			this->cmbMaterial->TabIndex = 0;
			// 
			// txtBrand
			// 
			this->txtBrand->Location = System::Drawing::Point(197, 149);
			this->txtBrand->Name = L"txtBrand";
			this->txtBrand->Size = System::Drawing::Size(100, 22);
			this->txtBrand->TabIndex = 1;
			// 
			// txtType
			// 
			this->txtType->Location = System::Drawing::Point(197, 88);
			this->txtType->Name = L"txtType";
			this->txtType->Size = System::Drawing::Size(100, 22);
			this->txtType->TabIndex = 2;
			// 
			// txtPrice
			// 
			this->txtPrice->Location = System::Drawing::Point(197, 213);
			this->txtPrice->Name = L"txtPrice";
			this->txtPrice->Size = System::Drawing::Size(100, 22);
			this->txtPrice->TabIndex = 3;
			// 
			// cmbSupplier
			// 
			this->cmbSupplier->FormattingEnabled = true;
			this->cmbSupplier->Location = System::Drawing::Point(472, 168);
			this->cmbSupplier->Name = L"cmbSupplier";
			this->cmbSupplier->Size = System::Drawing::Size(121, 24);
			this->cmbSupplier->TabIndex = 4;
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(371, 291);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(83, 23);
			this->btnSave->TabIndex = 5;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &AddForm::btnSave_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(93, 94);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 16);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Type";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(93, 149);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Brand";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(93, 219);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Price";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(382, 94);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Material";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(382, 176);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Supplier";
			// 
			// AddEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(853, 395);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->cmbSupplier);
			this->Controls->Add(this->txtPrice);
			this->Controls->Add(this->txtType);
			this->Controls->Add(this->txtBrand);
			this->Controls->Add(this->cmbMaterial);
			this->Name = L"AddEditForm";
			this->Text = L"AddForm";
			this->Load += gcnew System::EventHandler(this, &AddForm::AddForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ connString = "Server=localhost;Database=FurnitureDB;Uid=root;Pwd=pmpm2424;";
		MySqlConnection^ conn = gcnew MySqlConnection(connString);

		String^ sql = "INSERT INTO Furniture (type, brand, id_material, id_supplier, final_price) " +
			"VALUES (@type, @brand, @matId, @supId, @price)";

		MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

		try {
			conn->Open();
			cmd->Parameters->AddWithValue("@type", txtType->Text);
			cmd->Parameters->AddWithValue("@brand", txtBrand->Text);
			cmd->Parameters->AddWithValue("@matId", cmbMaterial->SelectedValue);
			cmd->Parameters->AddWithValue("@supId", cmbSupplier->SelectedValue);
			cmd->Parameters->AddWithValue("@price", Convert::ToDouble(txtPrice->Text));

			cmd->ExecuteNonQuery();
			MessageBox::Show("Successfully added");
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Save error: " + ex->Message);
		}
		finally {
			conn->Close();
		}
	}
private: System::Void AddForm_Load(System::Object^ sender, System::EventArgs^ e) {
	FillComboBoxes();
}
};
}
