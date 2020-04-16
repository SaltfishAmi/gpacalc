object MainForm: TMainForm
  Left = 92
  Top = 162
  Width = 761
  Height = 488
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = #21335#20140#24066#20013#22823#21307#38498#38468#23646#21307#23398#32844#19994#25216#26415#39640#32423#20013#23398#24179#22343#23398#20998#32489#28857#35745#31639#22120
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCanResize = FormCanResize
  OnCreate = FormCreate
  OnMouseWheel = FormMouseWheel
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 12
  object Label7: TLabel
    Left = 192
    Top = 370
    Width = 42
    Height = 12
    Caption = #20851#20110'...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -12
    Font.Name = #26032#23435#20307
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = Label7Click
  end
  object Label12: TLabel
    Left = 160
    Top = 368
    Width = 24
    Height = 12
    Cursor = crHandPoint
    Caption = #20027#39029
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -12
    Font.Name = #26032#23435#20307
    Font.Style = [fsUnderline]
    ParentFont = False
    Visible = False
    OnClick = Label12Click
  end
  object Label14: TLabel
    Left = 24
    Top = 376
    Width = 62
    Height = 13
    Caption = 'Debug Mode'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
    Visible = False
    OnClick = Label14Click
  end
  object Label15: TLabel
    Left = 32
    Top = 16
    Width = 48
    Height = 12
    Caption = #28155#21152#35838#31243
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label8: TLabel
    Left = 24
    Top = 432
    Width = 24
    Height = 12
    Caption = #27979#35797
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #26032#23435#20307
    Font.Style = []
    ParentFont = False
  end
  object grGeneral: TGroupBox
    Left = 24
    Top = 24
    Width = 209
    Height = 337
    Caption = #28155#21152#35838#31243
    TabOrder = 0
    object edName: TEdit
      Left = 16
      Top = 56
      Width = 177
      Height = 20
      Font.Charset = ANSI_CHARSET
      Font.Color = clGrayText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      Text = #35838#31243#21517#65288#21487#36873#65289
      OnEnter = edNameEnter
      OnExit = edNameExit
    end
    object grXf: TGroupBox
      Left = 16
      Top = 80
      Width = 177
      Height = 65
      Caption = #35838#31243#23398#20998#25968
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #26032#23435#20307
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object edXf: TEdit
        Left = 32
        Top = 28
        Width = 41
        Height = 20
        Font.Charset = ANSI_CHARSET
        Font.Color = clGrayText
        Font.Height = -12
        Font.Name = #26032#23435#20307
        Font.Style = []
        MaxLength = 2
        ParentFont = False
        TabOrder = 0
        Text = #25972#25968
        OnEnter = edXfEnter
        OnExit = edXfExit
        OnKeyPress = edGrKeyPress
      end
      object rdp0: TRadioButton
        Left = 96
        Top = 16
        Width = 49
        Height = 17
        Caption = '.0'
        Checked = True
        TabOrder = 1
        TabStop = True
      end
      object rdp5: TRadioButton
        Left = 96
        Top = 40
        Width = 49
        Height = 17
        Caption = '.5'
        TabOrder = 2
      end
    end
    object grGr: TGroupBox
      Left = 16
      Top = 152
      Width = 177
      Height = 137
      Caption = #35838#31243#25104#32489
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #26032#23435#20307
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      object Label1: TLabel
        Left = 112
        Top = 96
        Width = 12
        Height = 12
        Caption = #20998
      end
      object Label2: TLabel
        Left = 4
        Top = 120
        Width = 36
        Height = 12
        Caption = #19981#21450#26684
        Visible = False
      end
      object Label3: TLabel
        Left = 42
        Top = 120
        Width = 24
        Height = 12
        Caption = #21450#26684
        Visible = False
      end
      object Label4: TLabel
        Left = 82
        Top = 120
        Width = 12
        Height = 12
        Caption = #20013
        Visible = False
      end
      object Label5: TLabel
        Left = 118
        Top = 120
        Width = 12
        Height = 12
        Caption = #33391
        Visible = False
      end
      object Label6: TLabel
        Left = 152
        Top = 120
        Width = 12
        Height = 12
        Caption = #20248
        Visible = False
      end
      object Label13: TLabel
        Left = 16
        Top = 72
        Width = 120
        Height = 12
        Caption = #27880#65306#8220#36890#36807#8221#21363#21450#26684#12290
        Visible = False
      end
      object edGr: TEdit
        Left = 56
        Top = 93
        Width = 41
        Height = 20
        Font.Charset = ANSI_CHARSET
        Font.Color = clGrayText
        Font.Height = -12
        Font.Name = #26032#23435#20307
        Font.Style = []
        MaxLength = 3
        ParentFont = False
        TabOrder = 1
        Text = #25972#25968
        OnEnter = edXfEnter
        OnExit = edXfExit
        OnKeyPress = edGrKeyPress
      end
      object rdPnt: TRadioButton
        Left = 48
        Top = 24
        Width = 89
        Height = 17
        Caption = #30334#20998#21046#20998#25968
        Checked = True
        TabOrder = 0
        TabStop = True
        OnClick = rdPntClick
      end
      object rdLvl: TRadioButton
        Left = 48
        Top = 48
        Width = 81
        Height = 17
        Caption = #20116#27573#21046#31561#32423
        TabOrder = 2
        OnClick = rdLvlClick
      end
      object trkLvl: TTrackBar
        Left = 8
        Top = 88
        Width = 161
        Height = 33
        Max = 4
        Orientation = trHorizontal
        Frequency = 1
        Position = 3
        SelEnd = 0
        SelStart = 0
        TabOrder = 3
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        Visible = False
      end
    end
    object btnAdd: TButton
      Left = 16
      Top = 296
      Width = 177
      Height = 25
      Caption = #28155#21152#35838#31243
      Default = True
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #26032#23435#20307
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = btnAddClick
    end
    object btnMode: TButton
      Left = 16
      Top = 24
      Width = 177
      Height = 25
      Caption = #28857#20987#20999#25442#20026#33258#21160#27169#24335
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #26032#23435#20307
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = btnModeClick
    end
    object grAutomate: TGroupBox
      Left = 16
      Top = 56
      Width = 177
      Height = 265
      BiDiMode = bdRightToLeft
      Caption = #30331#24405
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentBiDiMode = False
      ParentFont = False
      TabOrder = 4
      Visible = False
      object Label9: TLabel
        Left = 16
        Top = 24
        Width = 48
        Height = 12
        Caption = #19968#21345#36890#21495
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #26032#23435#20307
        Font.Style = []
        ParentFont = False
      end
      object Label10: TLabel
        Left = 16
        Top = 72
        Width = 96
        Height = 12
        Caption = #32479#19968#36523#20221#35748#35777#23494#30721
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #26032#23435#20307
        Font.Style = []
        ParentFont = False
      end
      object Label11: TLabel
        Left = 16
        Top = 120
        Width = 36
        Height = 12
        Caption = #39564#35777#30721
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #26032#23435#20307
        Font.Style = []
        ParentFont = False
      end
      object labLength: TLabel
        Left = 148
        Top = 92
        Width = 6
        Height = 12
        BiDiMode = bdRightToLeft
        Caption = '0'
        ParentBiDiMode = False
        OnMouseDown = labLengthMouseDown
        OnMouseUp = labLengthMouseUp
        OnMouseLeave = labLengthMouseLeave
      end
      object btnVPN: TButton
        Left = 16
        Top = 168
        Width = 73
        Height = 25
        Caption = #30331#24405'VPN'
        ParentShowHint = False
        ShowHint = False
        TabOrder = 8
        OnClick = btnVPNClick
      end
      object edCardId: TEdit
        Left = 16
        Top = 40
        Width = 145
        Height = 20
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #26032#23435#20307
        Font.Style = []
        MaxLength = 9
        ParentFont = False
        TabOrder = 0
      end
      object edCardPw: TEdit
        Left = 16
        Top = 88
        Width = 129
        Height = 20
        Hint = #23601#26159#36827#25945#21153#22788#25110#32773#20449#24687#38376#25143#30340#37027#20010#23494#30721
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #26032#23435#20307
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        PasswordChar = '*'
        ShowHint = True
        TabOrder = 1
        OnChange = edCardPwChange
      end
      object edVercode: TEdit
        Left = 16
        Top = 136
        Width = 65
        Height = 20
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #26032#23435#20307
        Font.Style = []
        MaxLength = 4
        ParentFont = False
        TabOrder = 2
      end
      object btnGetVercode: TButton
        Left = 88
        Top = 135
        Width = 73
        Height = 21
        Caption = #33719#21462
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #26032#23435#20307
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = btnGetVercodeClick
      end
      object btnLogin: TButton
        Left = 88
        Top = 168
        Width = 73
        Height = 25
        Caption = #30331#24405#25945#21153#22788
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #26032#23435#20307
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = btnLoginClick
      end
      object btnReAddCourses: TButton
        Left = 16
        Top = 200
        Width = 145
        Height = 25
        Caption = #37325#26032#33719#21462#35838#31243#21015#34920
        Enabled = False
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        TabOrder = 5
        Visible = False
        OnClick = btnReAddCoursesClick
      end
      object btnInput: TButton
        Left = 16
        Top = 232
        Width = 73
        Height = 25
        Caption = #23548#20837
        TabOrder = 6
        OnClick = btnInputClick
      end
      object btnOutput: TButton
        Left = 88
        Top = 232
        Width = 73
        Height = 25
        Caption = #23548#20986
        TabOrder = 7
        OnClick = btnOutputClick
      end
    end
  end
  object StringGrid1: TXStringGrid
    Left = 256
    Top = 24
    Width = 465
    Height = 409
    ColCount = 7
    DefaultRowHeight = 18
    FixedCols = 0
    RowCount = 150
    GridLineWidth = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
    ScrollBars = ssVertical
    TabOrder = 3
    OnDblClick = StringGrid1DblClick
    OnMouseUp = StringGrid1MouseUp
    OnMouseWheelDown = StringGrid1MouseWheelDown
    OnMouseWheelUp = StringGrid1MouseWheelUp
    OnSelectCell = StringGrid1SelectCell
    FixedLineColor = clBlack
    Columns = <
      item
        HeaderFont.Charset = GB2312_CHARSET
        HeaderFont.Color = clWindowText
        HeaderFont.Height = -12
        HeaderFont.Name = #23435#20307
        HeaderFont.Style = []
        Caption = #35838#31243#21517#31216
        Width = 168
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        EditorInheritsCellProps = False
      end
      item
        HeaderFont.Charset = GB2312_CHARSET
        HeaderFont.Color = clWindowText
        HeaderFont.Height = -12
        HeaderFont.Name = #23435#20307
        HeaderFont.Style = []
        HeaderAlignment = taCenter
        Caption = #23398#20998
        Width = 28
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        Alignment = taCenter
        EditorInheritsCellProps = False
      end
      item
        HeaderFont.Charset = GB2312_CHARSET
        HeaderFont.Color = clWindowText
        HeaderFont.Height = -12
        HeaderFont.Name = #23435#20307
        HeaderFont.Style = []
        HeaderAlignment = taCenter
        Caption = #25104#32489
        Width = 40
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        Alignment = taCenter
        EditorInheritsCellProps = False
      end
      item
        HeaderFont.Charset = GB2312_CHARSET
        HeaderFont.Color = clWindowText
        HeaderFont.Height = -12
        HeaderFont.Name = #23435#20307
        HeaderFont.Style = []
        HeaderAlignment = taCenter
        Caption = #25104#32489#24615#36136
        Width = 56
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        Alignment = taCenter
        EditorInheritsCellProps = False
      end
      item
        HeaderFont.Charset = GB2312_CHARSET
        HeaderFont.Color = clWindowText
        HeaderFont.Height = -12
        HeaderFont.Name = #23435#20307
        HeaderFont.Style = []
        HeaderAlignment = taCenter
        Caption = #35838#31243#24615#36136
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        Alignment = taCenter
        EditorInheritsCellProps = False
      end
      item
        HeaderFont.Charset = GB2312_CHARSET
        HeaderFont.Color = clWindowText
        HeaderFont.Height = -12
        HeaderFont.Name = #23435#20307
        HeaderFont.Style = []
        HeaderAlignment = taCenter
        Caption = #32489#28857
        Width = 32
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        Alignment = taCenter
        EditorInheritsCellProps = False
      end
      item
        HeaderFont.Charset = ANSI_CHARSET
        HeaderFont.Color = clWindowText
        HeaderFont.Height = -12
        HeaderFont.Name = #23435#20307
        HeaderFont.Style = []
        HeaderAlignment = taCenter
        Caption = #21442#21152#35745#31639
        Width = 56
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Alignment = taCenter
        EditorInheritsCellProps = True
      end>
    OnCellProps = StringGrid1CellProps
    MultiLine = False
    ImmediateEditMode = False
    ColWidths = (
      168
      28
      40
      56
      64
      32
      56)
  end
  object btnCalc: TButton
    Left = 24
    Top = 392
    Width = 209
    Height = 41
    Caption = #35745#31639#24179#22343#23398#20998#32489#28857
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #26032#23435#20307
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = btnCalcClick
  end
  object CppWebBrowser1: TCppWebBrowser
    Left = -816
    Top = 128
    Width = 256
    Height = 136
    TabOrder = 2
    OnDownloadComplete = CppWebBrowser1DownloadComplete
    OnNavigateError = CppWebBrowser1NavigateError
    ControlData = {
      4C000000751A00000E0E00000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object edDebug: TRichEdit
    Left = 400
    Top = 440
    Width = 185
    Height = 89
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'edDebug')
    ParentFont = False
    TabOrder = 4
    Visible = False
    WordWrap = False
  end
  object CppWebBrowser2: TCppWebBrowser
    Left = -1024
    Top = 176
    Width = 300
    Height = 150
    TabOrder = 5
    ControlData = {
      4C000000021F0000810F00000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E12620A000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object chkScratch: TRadioButton
    Left = 72
    Top = 368
    Width = 57
    Height = 17
    Caption = #21038#21038#20048
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = chkScratchClick
  end
  object chkNormal: TRadioButton
    Left = 24
    Top = 368
    Width = 41
    Height = 17
    Caption = #27491#24120
    Checked = True
    TabOrder = 7
    TabStop = True
    OnClick = chkScratchClick
  end
  object chkGuess: TRadioButton
    Left = 128
    Top = 368
    Width = 57
    Height = 17
    Caption = #29468#25968#23383
    TabOrder = 8
    OnClick = chkScratchClick
  end
  object tmVercode: TTimer
    OnTimer = tmVercodeTimer
    Left = 112
    Top = 280
  end
  object tmLogin: TTimer
    OnTimer = tmLoginTimer
    Left = 144
    Top = 280
  end
  object ppmOnGrid: TPopupMenu
    Top = 280
    object mitScra: TMenuItem
      Caption = #26174#31034'(&S)'
      OnClick = mitScraClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object mitEditCourse: TMenuItem
      Caption = #32534#36753'(&T)'
      OnClick = mitEditCourseClick
    end
    object mitExclude: TMenuItem
      Caption = #21442#21152#35745#31639'(&E)'
      OnClick = mitExcludeClick
    end
    object mitExclAll: TMenuItem
      Caption = #20840#37096#25490#38500'(&A)'
      OnClick = mitExclAllClick
    end
    object mitIncludeAll: TMenuItem
      Caption = #20840#37096#21442#21152'(&N)'
      OnClick = mitIncludeAllClick
    end
    object mitDelete: TMenuItem
      Caption = #21024#38500'(&D)'
      OnClick = mitDeleteClick
    end
    object C1: TMenuItem
      Caption = #28165#31354'(&C)'
      object R1: TMenuItem
        Caption = 'Really clear all? (&R)'
        object mitClear: TMenuItem
          Caption = #26412#24403#12395#20840#37096#21066#38500#12375#12414#12377#12363#65311'(&H)'
          OnClick = mitClearClick
        end
      end
    end
  end
end
