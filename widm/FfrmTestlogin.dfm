object frmTestLogin: TfrmTestLogin
  Left = 231
  Top = 183
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Login'
  ClientHeight = 158
  ClientWidth = 439
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -21
  Font.Name = 'Comic Sans MS'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 29
  object Label1: TLabel
    Left = 16
    Top = 32
    Width = 67
    Height = 29
    Caption = 'Naam: '
  end
  object Button1: TButton
    Left = 56
    Top = 96
    Width = 121
    Height = 41
    Caption = 'OK'
    Default = True
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 232
    Top = 96
    Width = 121
    Height = 41
    Cancel = True
    Caption = 'Annuleren'
    TabOrder = 2
    OnClick = Button2Click
  end
  object txtName: TEdit
    Left = 104
    Top = 32
    Width = 321
    Height = 37
    TabOrder = 0
  end
end
