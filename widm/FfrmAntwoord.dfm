object frmAntwoord: TfrmAntwoord
  Left = 0
  Top = 0
  Width = 630
  Height = 22
  TabOrder = 0
  object cmdDelete: TButton
    Left = 560
    Top = 0
    Width = 70
    Height = 22
    Anchors = [akTop, akRight]
    Caption = 'Verwijderen'
    TabOrder = 0
    OnClick = cmdDeleteClick
  end
  object cboNaam: TComboBox
    Left = 312
    Top = 0
    Width = 241
    Height = 21
    Anchors = [akTop, akRight]
    ItemHeight = 13
    TabOrder = 1
  end
  object txtVraag: TEdit
    Left = 0
    Top = 0
    Width = 309
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 2
    OnChange = txtVraagChange
  end
end
