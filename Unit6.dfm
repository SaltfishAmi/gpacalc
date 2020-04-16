object Form6: TForm6
  Left = 236
  Top = 321
  BorderStyle = bsDialog
  Caption = #36755#20837#25991#20214#21517
  ClientHeight = 113
  ClientWidth = 313
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 272
    Top = 40
    Width = 30
    Height = 12
    Caption = '.gpml'
  end
  object Edit1: TEdit
    Left = 16
    Top = 36
    Width = 249
    Height = 20
    TabOrder = 0
  end
  object Button1: TButton
    Left = 136
    Top = 72
    Width = 75
    Height = 25
    Caption = #30830#23450
    Default = True
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 224
    Top = 72
    Width = 75
    Height = 25
    Caption = #21462#28040
    TabOrder = 2
    OnClick = Button2Click
  end
end
