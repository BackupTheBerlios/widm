object frmVraag: TfrmVraag
  Left = 0
  Top = 0
  Width = 634
  Height = 45
  TabOrder = 0
  object Label1: TLabel
    Left = 0
    Top = 5
    Width = 31
    Height = 13
    Caption = 'Vraag:'
  end
  object lblAw: TLabel
    Left = 24
    Top = 24
    Width = 60
    Height = 13
    Caption = 'Antwoorden:'
  end
  object Button1: TButton
    Left = 559
    Top = 0
    Width = 75
    Height = 22
    Anchors = [akTop, akRight]
    Caption = 'Verwijderen'
    TabOrder = 0
    OnClick = Button1Click
  end
  object chkSurvey: TCheckBox
    Left = 457
    Top = 4
    Width = 97
    Height = 17
    Anchors = [akTop, akRight]
    Caption = 'Survey-vraag'
    TabOrder = 1
  end
  object cboVraag: TComboBox
    Left = 40
    Top = 0
    Width = 410
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    ItemHeight = 13
    TabOrder = 2
    OnChange = cboVraagChange
  end
end
