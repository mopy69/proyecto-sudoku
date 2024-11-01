object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 769
  ClientWidth = 1098
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 119
    Top = 47
    Width = 42
    Height = 15
    Caption = 'campos'
  end
  object Label2: TLabel
    Left = 147
    Top = 80
    Width = 14
    Height = 15
    Caption = 'dir'
  end
  object Button1: TButton
    Left = 8
    Top = 16
    Width = 105
    Height = 25
    Caption = 'crear memoria'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 47
    Width = 105
    Height = 25
    Caption = 'pedir espacio'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 78
    Width = 105
    Height = 25
    Caption = 'liberar espacio'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 109
    Width = 105
    Height = 25
    Caption = 'crear matriz dis'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 140
    Width = 105
    Height = 25
    Caption = 'definir valor rep'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 8
    Top = 171
    Width = 105
    Height = 25
    Caption = 'dimensionar matd'
    TabOrder = 5
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 8
    Top = 202
    Width = 105
    Height = 25
    Caption = 'poner'
    TabOrder = 6
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 8
    Top = 233
    Width = 105
    Height = 25
    Caption = 'mostrar matriz'
    TabOrder = 7
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 8
    Top = 264
    Width = 105
    Height = 25
    Caption = 'mostrar memoria'
    TabOrder = 8
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 8
    Top = 295
    Width = 105
    Height = 25
    Caption = 'verificar sudoku'
    TabOrder = 9
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 8
    Top = 326
    Width = 105
    Height = 25
    Caption = 'retroceder en poner'
    TabOrder = 10
    OnClick = Button11Click
  end
  object Edit1: TEdit
    Left = 167
    Top = 44
    Width = 121
    Height = 23
    TabOrder = 11
  end
  object Edit2: TEdit
    Left = 167
    Top = 77
    Width = 121
    Height = 23
    TabOrder = 12
  end
  object Button12: TButton
    Left = 8
    Top = 504
    Width = 105
    Height = 25
    Caption = 'rellenar sudoku'
    TabOrder = 13
    OnClick = Button12Click
  end
  object Edit3: TEdit
    Left = 167
    Top = 265
    Width = 59
    Height = 23
    TabOrder = 14
    Text = '0'
  end
  object Edit4: TEdit
    Left = 232
    Top = 265
    Width = 56
    Height = 23
    TabOrder = 15
    Text = '20'
  end
end
