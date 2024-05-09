#pragma once

#include <msclr\marshal_cppstd.h>
#include "OpenGL.h"
#include <map>

namespace MyProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		OpenGL ^ opengl;

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::CheckBox^  checkBox1;


		int selectNames;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			opengl = gcnew OpenGL(this, 800, 600);
			selectNames = -1;
			vector <string> types = opengl->scene->GetTypesNames();

			comboBox1->Items->Clear();
			if (types.size() > 0)
			{
				for (unsigned i = 0; i < types.size(); i++)
					comboBox1->Items->Add(gcnew String(types[i].c_str()));
				comboBox1->Text = gcnew String(types[0].c_str());
			}
			UpdateSceneNames();
		}
	private:
		void UpdatePropertis()
		{
			map<int, string> names = opengl->scene->GetItemsNames();
			if ((selectNames > -1)&&(selectNames<names.size()))
			{
				map<string, string> props = opengl->scene->GetPropertisByIndex(selectNames);
				int i = 0;
				dataGridView1->ColumnCount = 2;
				dataGridView1->RowCount = props.size();
				dataGridView1->Columns[0]->Width = 80;
				dataGridView1->Columns[1]->Width = 80;
				dataGridView1->Columns[0]->ReadOnly = true;
				dataGridView1->Columns[1]->ReadOnly = false;
				dataGridView1->RowHeadersVisible = false;
				//dataGridView1->SortedColumn = -1;
				for (auto it = props.begin(); it != props.end(); ++it)
				{
					dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(it->first.c_str());
					dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(it->second.c_str());

					i++;
				}
			}
		}

		void UpdateSceneNames()
		{
			//selectNames = -1;
			
			checkedListBox1->Items->Clear();
			if (opengl != nullptr)
				if (opengl->scene != nullptr)
				{
					map<int, string> names = opengl->scene->GetItemsNames();
					if (names.size() > 0)
					{
						int i = 0;
						for (auto it = names.begin(); it != names.end(); ++it)
						{
							checkedListBox1->Items->Add(gcnew String(it->second.c_str()), opengl->scene->ItemIsVisible(i));
							
							i++;
						}
						if (selectNames==-1)
							selectNames = 0;
					}
					UpdatePropertis();
				}
				
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->checkedListBox1);
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel1->Location = System::Drawing::Point(817, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(373, 612);
			this->panel1->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->checkBox1);
			this->panel3->Controls->Add(this->button7);
			this->panel3->Controls->Add(this->comboBox1);
			this->panel3->Controls->Add(this->button5);
			this->panel3->Controls->Add(this->button4);
			this->panel3->Location = System::Drawing::Point(25, 451);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(336, 75);
			this->panel3->TabIndex = 16;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(141, 43);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(71, 23);
			this->button7->TabIndex = 19;
			this->button7->Text = L"Clone Item";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(11, 14);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(124, 21);
			this->comboBox1->TabIndex = 18;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(141, 14);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(71, 23);
			this->button5->TabIndex = 17;
			this->button5->Text = L"Add Item";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(233, 14);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(72, 23);
			this->button4->TabIndex = 16;
			this->button4->Text = L"Delete Item";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button6);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Location = System::Drawing::Point(25, 532);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(336, 68);
			this->panel2->TabIndex = 9;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(158, 37);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(44, 23);
			this->button6->TabIndex = 20;
			this->button6->Text = L"Clear";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(17, 37);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(48, 23);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Load";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(91, 37);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(48, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Save";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(305, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(24, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"...";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(17, 11);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(286, 20);
			this->textBox1->TabIndex = 9;
			this->textBox1->Text = L"scene1.xml";
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(25, 36);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(151, 409);
			this->checkedListBox1->TabIndex = 4;
			this->checkedListBox1->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &MyForm::checkedListBox1_ItemCheck);
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::checkedListBox1_SelectedIndexChanged);
			this->checkedListBox1->SelectedValueChanged += gcnew System::EventHandler(this, &MyForm::checkedListBox1_SelectedValueChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Column1, 
				this->Column2});
			this->dataGridView1->Location = System::Drawing::Point(199, 36);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView1->Size = System::Drawing::Size(162, 406);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellEndEdit);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Property";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 80;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Value";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 80;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(11, 47);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(97, 17);
			this->checkBox1->TabIndex = 20;
			this->checkBox1->Text = L"Mouse Camera";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1190, 612);
			this->Controls->Add(this->panel1);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		opengl->Render();
}

private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	switch (e->KeyCode)
	{
	case System::Windows::Forms::Keys::W:
		opengl->camera->KeyDown('w');
		break;
	case System::Windows::Forms::Keys::S:
		opengl->camera->KeyDown('s');
		break;
	case System::Windows::Forms::Keys::A:
		opengl->camera->KeyDown('a');
		break;
	case System::Windows::Forms::Keys::D:
		opengl->camera->KeyDown('d');
		break;
	case System::Windows::Forms::Keys::Q:
		opengl->camera->KeyDown('q');
		break;
	case System::Windows::Forms::Keys::E:
		opengl->camera->KeyDown('e');
		break;
	case System::Windows::Forms::Keys::Z:
		opengl->camera->KeyDown('z');
		break;
	case System::Windows::Forms::Keys::X:
		opengl->camera->KeyDown('x');
		break;
	default:
		break;
	}
}
private: System::Void treeView1_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
	 selectNames = e->Node->Index;
	 UpdatePropertis();
}
private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}

string SystemToStl(String ^s)
{
	using namespace Runtime::InteropServices;
	const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	return string(ptr);
}

private: System::Void dataGridView1_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	string property = SystemToStl(dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString());
	string value = SystemToStl(dataGridView1->Rows[e->RowIndex]->Cells[1]->Value->ToString());
	opengl->scene->UpdateProperty(selectNames, property, value);
	
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	selectNames = checkedListBox1->SelectedIndex;
	if (selectNames>-1)
	{
		opengl->scene->SetVisibleItem(selectNames, checkedListBox1->GetItemChecked(selectNames));
		//UpdateSceneNames();
		UpdatePropertis();
	}
}
private: System::Void checkedListBox1_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void checkedListBox1_ItemCheck(System::Object^  sender, System::Windows::Forms::ItemCheckEventArgs^  e) {
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	// add
	string name = msclr::interop::marshal_as<std::string>(comboBox1->Text);
	
	opengl->scene->AddItem(name);
	UpdateSceneNames();
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 opengl->scene->Clear();
			 UpdateSceneNames();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 opengl->scene->DeleteItem(checkedListBox1->SelectedIndex);
			 UpdateSceneNames();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 string name = msclr::interop::marshal_as<std::string>(textBox1->Text);
			 opengl->scene->Load(name);
			 UpdateSceneNames();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 string name = msclr::interop::marshal_as<std::string>(textBox1->Text);
			 opengl->scene->Save(name);
			 UpdateSceneNames();
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 opengl->scene->CloneItem(checkedListBox1->SelectedIndex);
			 UpdateSceneNames();
		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 opengl->camera->SetEnabled(checkBox1->Checked);
		 }
};
}
