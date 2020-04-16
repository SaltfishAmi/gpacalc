object frmGuess: TfrmGuess
  Left = 247
  Top = 177
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = #29468#25968#23383
  ClientHeight = 217
  ClientWidth = 353
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object Label2: TLabel
    Left = 16
    Top = 72
    Width = 321
    Height = 73
    Alignment = taCenter
    AutoSize = False
    Caption = '1.0-4.8'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -75
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 232
    Top = 26
    Width = 36
    Height = 12
    Caption = #22823#20102#65281
  end
  object Button2: TButton
    Left = 264
    Top = 16
    Width = 73
    Height = 33
    Caption = #19979#19968#20010#25968#23383
    Default = True
    Enabled = False
    TabOrder = 0
    OnClick = Button2Click
  end
  object Edit2: TEdit
    Left = 16
    Top = 16
    Width = 209
    Height = 32
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Microsoft Sans Serif'
    Font.Style = []
    MaxLength = 3
    ParentFont = False
    TabOrder = 1
    OnKeyPress = Edit2KeyPress
  end
  object Button1: TButton
    Left = 16
    Top = 176
    Width = 153
    Height = 25
    Caption = #25105#30693#36947#20102
    Enabled = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 184
    Top = 176
    Width = 153
    Height = 25
    Caption = #19979#27425#21543#8230
    TabOrder = 3
    OnClick = Button3Click
  end
end
