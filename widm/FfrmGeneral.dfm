object frmGeneral: TfrmGeneral
  Left = 334
  Top = 315
  Width = 793
  Height = 525
  Caption = 'Wie Is De Mol'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 785
    Height = 471
    ActivePage = tsTests
    Align = alClient
    TabOrder = 0
    object tsAlgemeen: TTabSheet
      Caption = 'Algemeen'
      OnEnter = tsAlgemeenEnter
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 777
        Height = 443
        Align = alClient
        BevelOuter = bvNone
        UseDockManager = False
        TabOrder = 0
        object Label1: TLabel
          Left = 8
          Top = 8
          Width = 150
          Height = 13
          Caption = 'Algemene eigenschappen:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object GroupBox1: TGroupBox
          Left = 8
          Top = 32
          Width = 764
          Height = 65
          Anchors = [akLeft, akTop, akRight]
          Caption = 'Beheerderstype: '
          TabOrder = 0
          object optAW: TRadioButton
            Left = 8
            Top = 16
            Width = 748
            Height = 17
            Anchors = [akLeft, akTop, akRight]
            Caption = 
              'Alwetende modus - De beheerder kan de identiteit van de mol en d' +
              'e uitslagen van de executies zien'
            Checked = True
            TabOrder = 0
            TabStop = True
            OnClick = optAWClick
          end
          object optNAW: TRadioButton
            Left = 8
            Top = 32
            Width = 748
            Height = 17
            Anchors = [akLeft, akTop, akRight]
            Caption = 
              'Niet-alwetende modus - De beheerder kan wel aanpassingen maken, ' +
              'maar komt de identiteit van de mol niet te weten.'
            TabOrder = 1
            OnClick = optNAWClick
          end
        end
        object GroupBox2: TGroupBox
          Left = 8
          Top = 104
          Width = 764
          Height = 331
          Anchors = [akLeft, akTop, akRight, akBottom]
          Caption = 'Kandidaten: '
          TabOrder = 1
          object lstKandi: TListView
            Left = 8
            Top = 16
            Width = 628
            Height = 307
            Anchors = [akLeft, akTop, akRight, akBottom]
            Columns = <
              item
                Caption = 'Naam'
                Width = 140
              end
              item
                Caption = 'Actief'
              end
              item
                Caption = 'Mol'
              end
              item
                Caption = 'Survey'
              end>
            SortType = stText
            TabOrder = 0
            ViewStyle = vsReport
            OnSelectItem = lstKandiSelectItem
          end
          object chkMol: TCheckBox
            Left = 643
            Top = 16
            Width = 113
            Height = 17
            Anchors = [akTop, akRight]
            Caption = 'Persoon is de mol'
            TabOrder = 1
            OnClick = chkMolClick
          end
          object chkActief: TCheckBox
            Left = 643
            Top = 40
            Width = 97
            Height = 17
            Anchors = [akTop, akRight]
            Caption = 'Persoon is actief'
            TabOrder = 2
            OnClick = chkActiefClick
          end
          object Button1: TButton
            Left = 643
            Top = 266
            Width = 113
            Height = 25
            Anchors = [akRight, akBottom]
            Caption = 'Willekeurige mol'
            TabOrder = 3
            OnClick = Button1Click
          end
          object Button2: TButton
            Left = 643
            Top = 234
            Width = 113
            Height = 25
            Anchors = [akRight, akBottom]
            Caption = 'Nieuwe kandidaat'
            TabOrder = 4
            OnClick = Button2Click
          end
          object Button3: TButton
            Left = 643
            Top = 298
            Width = 113
            Height = 25
            Anchors = [akRight, akBottom]
            Caption = 'Verwijder kandidaat'
            TabOrder = 5
            OnClick = Button3Click
          end
          object Button4: TButton
            Left = 640
            Top = 64
            Width = 113
            Height = 25
            Anchors = [akTop, akRight]
            Caption = 'Verwijder survey'
            TabOrder = 6
            OnClick = Button4Click
          end
        end
        object Button5: TButton
          Left = 667
          Top = 7
          Width = 104
          Height = 25
          Anchors = [akTop, akRight]
          Caption = 'Survey afnemen'
          TabOrder = 2
          OnClick = Button5Click
        end
      end
    end
    object tsTests: TTabSheet
      Caption = 'Tests'
      ImageIndex = 1
      OnShow = tsTestsEnter
      object Splitter1: TSplitter
        Left = 161
        Top = 0
        Width = 3
        Height = 443
        Cursor = crHSplit
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 161
        Height = 443
        Align = alLeft
        TabOrder = 0
        object Label2: TLabel
          Left = 8
          Top = 8
          Width = 94
          Height = 13
          Caption = 'Aangemaakte tests:'
        end
        object lstTests: TListView
          Left = 8
          Top = 56
          Width = 145
          Height = 381
          Anchors = [akLeft, akTop, akRight, akBottom]
          Columns = <>
          SortType = stText
          TabOrder = 0
          ViewStyle = vsList
          OnChange = lstTestsChange
          OnSelectItem = lstTestsSelectItem
        end
        object Button6: TButton
          Left = 8
          Top = 32
          Width = 73
          Height = 25
          Caption = 'Toevoegen'
          TabOrder = 1
          OnClick = Button6Click
        end
        object Button7: TButton
          Left = 82
          Top = 32
          Width = 73
          Height = 25
          Anchors = [akTop, akRight]
          Caption = 'Verwijderen'
          TabOrder = 2
          OnClick = Button7Click
        end
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 248
    Top = 8
    object File1: TMenuItem
      Caption = '&File'
      object Newproject1: TMenuItem
        Caption = 'New project'
        ShortCut = 16462
      end
      object Openproject1: TMenuItem
        Caption = 'Open project'
        ShortCut = 16463
        OnClick = Openproject1Click
      end
      object Saveproject1: TMenuItem
        Caption = 'Save project'
        ShortCut = 16467
        OnClick = Saveproject1Click
      end
      object Saveprojectas1: TMenuItem
        Caption = 'Save project as....'
        OnClick = Saveprojectas1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
        ShortCut = 16465
      end
    end
    object Help1: TMenuItem
      Caption = '&Help'
      object About1: TMenuItem
        Caption = '&About...'
        OnClick = About1Click
      end
    end
  end
  object dlgOpen: TOpenDialog
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Title = 'Open project...'
    Left = 280
    Top = 8
  end
  object dlgSave: TSaveDialog
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Title = 'Sla project op als...'
    Left = 312
    Top = 8
  end
end
