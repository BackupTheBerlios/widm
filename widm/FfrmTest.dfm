object frmTest: TfrmTest
  Left = 0
  Top = 0
  Width = 1041
  Height = 485
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
    Top = 144
    Width = 37
    Height = 13
    Caption = 'Vragen:'
  end
  object pnlBelow: TPanel
    Left = 0
    Top = 172
    Width = 1035
    Height = 185
    Anchors = [akLeft, akTop, akRight]
    BevelInner = bvRaised
    BevelOuter = bvNone
    Caption = 'pnlBelow'
    TabOrder = 0
    object Label2: TLabel
      Left = 16
      Top = 8
      Width = 47
      Height = 13
      Caption = 'Uitslagen:'
    end
    object Label4: TLabel
      Left = 891
      Top = 48
      Width = 86
      Height = 13
      Anchors = [akTop, akRight]
      Caption = 'Aantal pasvragen:'
    end
    object lstUitslag: TListView
      Left = 16
      Top = 24
      Width = 868
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
      Left = 891
      Top = 24
      Width = 139
      Height = 17
      Anchors = [akTop, akRight]
      Caption = 'Persoon heeft vrijstelling'
      TabOrder = 1
      OnClick = chkVrijClick
    end
    object txtPas: TEdit
      Left = 987
      Top = 45
      Width = 41
      Height = 21
      Anchors = [akTop, akRight]
      TabOrder = 2
      OnChange = txtPasChange
    end
    object cmdDeletePers: TButton
      Left = 891
      Top = 72
      Width = 137
      Height = 25
      Anchors = [akTop, akRight]
      Caption = 'Verwijder testresultaten'
      TabOrder = 3
      OnClick = cmdDeletePersClick
    end
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 24
    Width = 1027
    Height = 113
    Anchors = [akLeft, akTop, akRight]
    Caption = 'Executie-eigenschappen '
    TabOrder = 1
    object Label5: TLabel
      Left = 8
      Top = 36
      Width = 33
      Height = 13
      Caption = 'Status:'
    end
    object lblStatus: TLabel
      Left = 63
      Top = 36
      Width = 956
      Height = 13
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
    end
    object Label1: TLabel
      Left = 9
      Top = 57
      Width = 144
      Height = 13
      Caption = 'Aantal mensen te executeren: '
    end
    object chkExecutie: TCheckBox
      Left = 8
      Top = 16
      Width = 145
      Height = 17
      Caption = 'Executie uitgevoerd'
      TabOrder = 0
    end
    object txtAantal: TEdit
      Left = 168
      Top = 53
      Width = 33
      Height = 21
      TabOrder = 1
      Text = '1'
    end
    object cmdTest: TButton
      Left = 104
      Top = 76
      Width = 89
      Height = 25
      Caption = 'Start Test'
      TabOrder = 2
      OnClick = cmdTestClick
    end
    object Button1: TButton
      Left = 200
      Top = 76
      Width = 89
      Height = 25
      Caption = 'Executievolgorde'
      TabOrder = 3
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 296
      Top = 76
      Width = 89
      Height = 25
      Caption = 'Start Executie'
      TabOrder = 4
      OnClick = Button2Click
    end
    object cmdPercentage: TButton
      Left = 8
      Top = 76
      Width = 89
      Height = 25
      Caption = 'Aantal goed'
      TabOrder = 5
      OnClick = cmdPercentageClick
    end
    object chkPercentage: TCheckBox
      Left = 240
      Top = 56
      Width = 169
      Height = 17
      Caption = 'Percentage weergeven'
      TabOrder = 6
    end
  end
end
