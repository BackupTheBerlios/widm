object frmTest: TfrmTest
  Left = 0
  Top = 0
  Width = 973
  Height = 475
  Anchors = [akLeft, akRight]
  TabOrder = 0
  object lblTitel: TLabel
    Left = 0
    Top = 0
    Width = 65
    Height = 13
    Caption = 'Test: Testx'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblVragen: TLabel
    Left = 16
    Top = 72
    Width = 37
    Height = 13
    Caption = 'Vragen:'
  end
  object Label5: TLabel
    Left = 16
    Top = 48
    Width = 33
    Height = 13
    Caption = 'Status:'
  end
  object lblStatus: TLabel
    Left = 72
    Top = 48
    Width = 585
    Height = 13
    Anchors = [akLeft, akTop, akRight]
    AutoSize = False
  end
  object Label1: TLabel
    Left = 665
    Top = 49
    Width = 144
    Height = 13
    Anchors = [akTop, akRight]
    Caption = 'Aantal mensen te executeren: '
  end
  object chkExecutie: TCheckBox
    Left = 16
    Top = 24
    Width = 145
    Height = 17
    Caption = 'Executie uitgevoerd'
    TabOrder = 0
  end
  object pnlBelow: TPanel
    Left = 0
    Top = 100
    Width = 973
    Height = 185
    Anchors = [akLeft, akTop, akRight]
    BevelInner = bvRaised
    BevelOuter = bvNone
    Caption = 'pnlBelow'
    TabOrder = 1
    object Label2: TLabel
      Left = 16
      Top = 8
      Width = 47
      Height = 13
      Caption = 'Uitslagen:'
    end
    object Label4: TLabel
      Left = 829
      Top = 48
      Width = 86
      Height = 13
      Anchors = [akTop, akRight]
      Caption = 'Aantal pasvragen:'
    end
    object lstUitslag: TListView
      Left = 16
      Top = 24
      Width = 806
      Height = 150
      Anchors = [akLeft, akTop, akRight]
      Columns = <
        item
          Caption = 'Naam'
          Width = 150
        end
        item
          Caption = 'Actief'
        end
        item
          Caption = 'Extra'#39's'
          Width = 100
        end
        item
          Caption = 'Klaar'
        end
        item
          Caption = 'Uitslag'
        end
        item
          Caption = 'Antwoorden'
          Width = 0
        end
        item
          Caption = 'Tijd'
        end>
      ReadOnly = True
      TabOrder = 0
      ViewStyle = vsReport
      OnClick = lstUitslagClick
    end
    object chkVrij: TCheckBox
      Left = 829
      Top = 24
      Width = 139
      Height = 17
      Anchors = [akTop, akRight]
      Caption = 'Persoon heeft vrijstelling'
      TabOrder = 1
      OnClick = chkVrijClick
    end
    object txtPas: TEdit
      Left = 925
      Top = 45
      Width = 41
      Height = 21
      Anchors = [akTop, akRight]
      TabOrder = 2
      OnChange = txtPasChange
    end
    object cmdDeletePers: TButton
      Left = 829
      Top = 72
      Width = 137
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Verwijder testresultaten'
      TabOrder = 3
      OnClick = cmdDeletePersClick
    end
  end
  object Button1: TButton
    Left = 781
    Top = 20
    Width = 89
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Executievolgorde'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 877
    Top = 20
    Width = 89
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Start Executie'
    TabOrder = 3
    OnClick = Button2Click
  end
  object cmdTest: TButton
    Left = 685
    Top = 20
    Width = 89
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Start Test'
    TabOrder = 4
    OnClick = cmdTestClick
  end
  object txtAantal: TEdit
    Left = 839
    Top = 45
    Width = 33
    Height = 21
    Anchors = [akTop, akRight]
    TabOrder = 5
    Text = '1'
  end
  object cmdPercentage: TButton
    Left = 876
    Top = 44
    Width = 89
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Aantal goed'
    TabOrder = 6
    OnClick = cmdPercentageClick
  end
end
