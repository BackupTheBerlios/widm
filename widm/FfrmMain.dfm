object frmMain: TfrmMain
  Left = 312
  Top = 228
  Width = 648
  Height = 465
  Caption = 'Wie Is De Mol'
  Color = clAppWorkSpace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = mnuMain
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 640
    Height = 25
    Align = alTop
    TabOrder = 0
    object Button1: TButton
      Left = 0
      Top = 0
      Width = 145
      Height = 25
      Caption = 'Algemene eigenschappen'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 152
      Top = 0
      Width = 145
      Height = 25
      Caption = 'Tests'
      TabOrder = 1
    end
  end
  object mnuMain: TMainMenu
    Top = 48
    object Bestand1: TMenuItem
      Caption = '&Bestand'
      object Nieuwewerkomgeving1: TMenuItem
        Caption = 'Nieuw'
        ShortCut = 16462
      end
      object Opslaanwerkomgeving1: TMenuItem
        Caption = '&Opslaan'
        ShortCut = 16467
      end
      object Opslaanals1: TMenuItem
        Caption = 'Opslaan als...'
      end
      object Sluitenwerkcomgeving1: TMenuItem
        Caption = '&Sluiten'
        ShortCut = 16451
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Afsluiten1: TMenuItem
        Caption = '&Afsluiten'
        ShortCut = 16465
      end
    end
  end
end
