object frmEditCourse: TfrmEditCourse
  Left = 394
  Top = 303
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #32534#36753#35838#31243#20449#24687
  ClientHeight = 153
  ClientWidth = 433
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 16
    Top = 48
    Width = 60
    Height = 12
    Caption = #21407#35838#31243#20449#24687
  end
  object Label2: TLabel
    Left = 16
    Top = 80
    Width = 60
    Height = 12
    Caption = #26032#35838#31243#20449#24687
  end
  object Label3: TLabel
    Left = 168
    Top = 16
    Width = 48
    Height = 12
    Caption = #35838#31243#21517#31216
  end
  object Label4: TLabel
    Left = 288
    Top = 16
    Width = 24
    Height = 12
    Caption = #23398#20998
  end
  object Label5: TLabel
    Left = 328
    Top = 16
    Width = 24
    Height = 12
    Caption = #25104#32489
  end
  object Label6: TLabel
    Left = 368
    Top = 16
    Width = 48
    Height = 12
    Caption = #21442#21152#35745#31639
  end
  object lblZero: TLabel
    Left = 304
    Top = 72
    Width = 12
    Height = 12
    Caption = '.0'
    Color = clBtnFace
    ParentColor = False
    OnClick = lblZeroClick
  end
  object lblFive: TLabel
    Left = 304
    Top = 88
    Width = 12
    Height = 12
    Caption = '.5'
    OnClick = lblFiveClick
  end
  object btnOK: TButton
    Left = 256
    Top = 112
    Width = 75
    Height = 25
    Caption = #30830#23450
    Default = True
    TabOrder = 0
    OnClick = btnOKClick
  end
  object btnCancel: TButton
    Left = 344
    Top = 112
    Width = 75
    Height = 25
    Cancel = True
    Caption = #21462#28040
    TabOrder = 1
    OnClick = btnCancelClick
  end
  object edOrName: TEdit
    Left = 96
    Top = 44
    Width = 185
    Height = 20
    Color = clBtnFace
    Enabled = False
    ReadOnly = True
    TabOrder = 2
  end
  object edOrXf: TEdit
    Left = 288
    Top = 44
    Width = 25
    Height = 20
    Color = clBtnFace
    Enabled = False
    ReadOnly = True
    TabOrder = 3
  end
  object edOrGr: TEdit
    Left = 320
    Top = 44
    Width = 41
    Height = 20
    Color = clBtnFace
    Enabled = False
    ReadOnly = True
    TabOrder = 4
  end
  object chOrInc: TCheckBox
    Left = 384
    Top = 44
    Width = 17
    Height = 17
    Caption = 'chOrInc'
    Enabled = False
    TabOrder = 5
  end
  object edNwName: TEdit
    Left = 96
    Top = 76
    Width = 185
    Height = 20
    TabOrder = 6
    OnChange = Validate
  end
  object edNwXf: TEdit
    Left = 288
    Top = 76
    Width = 17
    Height = 20
    MaxLength = 2
    TabOrder = 7
    OnChange = Validate
  end
  object edNwGr: TEdit
    Left = 320
    Top = 76
    Width = 41
    Height = 20
    TabOrder = 8
    OnChange = Validate
  end
  object chNwInc: TCheckBox
    Left = 384
    Top = 76
    Width = 17
    Height = 17
    Caption = 'chOrInc'
    TabOrder = 9
    OnClick = Validate
  end
end
