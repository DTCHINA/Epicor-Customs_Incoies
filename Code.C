// **************************************************
// Custom code for CustShipForm
// Created: 8/19/2014 3:34:43 PM
// **************************************************
using System;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Windows.Forms;
using Epicor.Mfg.BO;
using Epicor.Mfg.UI;
using Epicor.Mfg.UI.Adapters;
using Epicor.Mfg.UI.Customization;
using Epicor.Mfg.UI.ExtendedProps;
using Epicor.Mfg.UI.FormFunctions;
using Epicor.Mfg.UI.FrameWork;
using Epicor.Mfg.UI.Searches;


public class Script
{
	// ** Wizard Insert Location - Do Not Remove 'Begin/End Wizard Added Module Level Variables' Comments! **
	// Begin Wizard Added Module Level Variables **
	private EpiDataView edvShipHead;
	// End Wizard Added Module Level Variables **

	// Add Custom Module Level Variables Here **

	public void InitializeCustomCode()
	{
		// ** Wizard Insert Location - Do not delete 'Begin/End Wizard Added Variable Initialization' lines **
		// Begin Wizard Added Variable Initialization
			edvShipHead = ((EpiDataView)(oTrans.EpiDataViews["ShipHead"]));

		// End Wizard Added Variable Initialization

		// Begin Wizard Added Custom Method Calls

		this.BTNCalc.Click += new System.EventHandler(this.BTNCalc_Click);
		this.epiBT_Add_Skid.Click += new System.EventHandler(this.epiBT_Add_Skid_Click);
		// End Wizard Added Custom Method Calls
	}

	public void DestroyCustomCode()
	{
		// ** Wizard Insert Location - Do not delete 'Begin/End Wizard Added Object Disposal' lines **
		// Begin Wizard Added Object Disposal

		this.BTNCalc.Click -= new System.EventHandler(this.BTNCalc_Click);
		this.epiBT_Add_Skid.Click -= new System.EventHandler(this.epiBT_Add_Skid_Click);
		// End Wizard Added Object Disposal

		// Begin Custom Code Disposal

		// End Custom Code Disposal
	}

	private void BTNCalc_Click(object sender, System.EventArgs args)
	{
		// ** Place Event Handling Code Here **
	
		string fieldContents = string.Empty;
		edvShipHead.dataView[edvShipHead.Row]["Character10"]= fieldContents;	
	
		int X = 0;	
		int Y = 0;	
		int Z = 0;	
		int RollQty = 0;
		int BoxQty = 0;
		int SkidQty = 0;
	
		if (Int32.TryParse(epiText_EX_Small.Text,out X)) 	   //Extra Small box
		{
			fieldContents = string.Format("{0} - {1} AT {2} {3}",X,"Box(s)","14 x 12 x 9",Environment.NewLine);
			edvShipHead.dataView[edvShipHead.Row]["Character10"]+= fieldContents;
			BoxQty += X;
		}
	
		if (Int32.TryParse(epiText_Small.Text,out X)) 		  //Small Box
		{
			fieldContents = string.Format("{0} - {1} AT {2} {3}",X,"Box(s)","22 x 20 x 13", Environment.NewLine);
			edvShipHead.dataView[edvShipHead.Row]["Character10"]+= fieldContents;
			BoxQty += X;
		}
	
		if (Int32.TryParse(epiText_MED.Text,out X)) 			//Med Box
		{
			fieldContents = string.Format("{0} - {1} AT {2} {3}",X,"Box(s)","35 x 20 x 24",Environment.NewLine);
			edvShipHead.dataView[edvShipHead.Row]["Character10"]+= fieldContents;
			BoxQty += X;
		}
	
		if (Int32.TryParse(epiText_Master.Text,out X)) 		 //Master Box
		{
			fieldContents = string.Format("{0} - {1} AT {2} {3}",X,"Box(s)","31 x 24 x 15", Environment.NewLine);
			edvShipHead.dataView[edvShipHead.Row]["Character10"]+= fieldContents;
			BoxQty += X;
		}
	
		if (Int32.TryParse(epiText_Box_FB.Text,out X)) 		 //FB 24 24 24
		{
			fieldContents = string.Format("{0} - {1} AT {2} {3}",X,"Box(s)","24 x 24 x 24", Environment.NewLine);
			edvShipHead.dataView[edvShipHead.Row]["Character10"]+= fieldContents;
			BoxQty += X;
		}
	
		if (Int32.TryParse(epiText_Box_DC.Text,out X)) 		 //DC 35 24 15
		{
			fieldContents = string.Format("{0} - {1} AT {2} {3}",X,"Box(s)","35 x 24 x 15", Environment.NewLine);
			edvShipHead.dataView[edvShipHead.Row]["Character10"]+= fieldContents;
			BoxQty += X;
		}
	
		if (Int32.TryParse(epiText_Box_BMFB.Text,out X)) 		 //BM FAB 24 22 15
		{
			fieldContents = string.Format("{0} - {1} AT {2} {3}",X,"Box(s)","24 x 22 x 15", Environment.NewLine);
			edvShipHead.dataView[edvShipHead.Row]["Character10"]+= fieldContents;
			BoxQty += X;
		}
	
		if (Int32.TryParse(epiText_Box_Lea.Text,out X)) 		 //Leather 22 x 20 x 12.5
		{
			fieldContents = string.Format("{0} - {1} AT {2} {3}",X,"Box(s)","22 x 20 x 12.5", Environment.NewLine);
			edvShipHead.dataView[edvShipHead.Row]["Character10"]+= fieldContents;
			BoxQty += X;
		}
	
		if (Int32.TryParse(epiText_Box_Mbox.Text,out X)) 		 //M-Box 38 x 27 x 13
		{
			fieldContents = string.Format("{0} - {1} AT {2} {3}",X,"Box(s)","38 x 27 x 13", Environment.NewLine);
			edvShipHead.dataView[edvShipHead.Row]["Character10"]+= fieldContents;
			BoxQty += X;
		}
	
		if (Int32.TryParse(epiText_Box_JFRAC.Text,out X)) 		 //41 x 27 x 13
		{
			fieldContents = string.Format("{0} - {1} AT {2} {3}",X,"Box(s)","41 x 27 x 13", Environment.NewLine);
			edvShipHead.dataView[edvShipHead.Row]["Character10"]+= fieldContents;
			BoxQty += X;
		}
	
		if (Int32.TryParse(txtRollQty.Text,out Z)) 			 //Rolls
		{
			fieldContents = string.Format("{0} - {1} AT {2} Dia{3} Length{4}",
				Z,
				"Roll(s)", 
				TXT_Roll_D.Text,
				TXT_Roll_L.Text,
				Environment.NewLine);
			edvShipHead.dataView[edvShipHead.Row]["Character10"]+= fieldContents;
			RollQty += Z;
		}
	
		if (Int32.TryParse(epiText_Skid_ODD.Text,out Y)) 		 //SKID Standard
		{
			
			fieldContents = string.Format("{0} - {1} AT L {2} x W {3} x H {4}{5}",
				Y,
				"Skid(s)",
				epiText_Skid_ODD_L.Text,
				epiText_Skid_ODD_W.Text,
				epiText_Skid_ODD_H.Text,
				Environment.NewLine);
	
			edvShipHead.dataView[edvShipHead.Row]["Character10"]+= fieldContents;
			SkidQty += Y;
		}
	
		//Number of boxes
		edvShipHead.dataView[edvShipHead.Row]["Number01"]= BoxQty;
		//Number of Skids
		edvShipHead.dataView[edvShipHead.Row]["Number02"]= SkidQty;
		//Number of Rolls
		edvShipHead.dataView[edvShipHead.Row]["Number03"]= RollQty;
	
	
		//MessageBox.Show(BoxQty.ToString());
		//MessageBox.Show(RollQty.ToString());
		//MessageBox.Show(SkidQty.ToString());
	}

	private void epiBT_Add_Skid_Click(object sender, System.EventArgs args)
	{
		// ** Place Event Handling Code Here **

		string addfieldContents = string.Empty;
		//dvShipHead.dataView[edvShipHead.Row]["Character10"]= addfieldContents;	
	
		int Y = 0;	
		int SkidQty = 0;
		int SkidQty_before = 0;


		if (Int32.TryParse(epiText_Skid_ODD.Text,out Y)) 		 //SKID Standard
		{
			
			addfieldContents = string.Format("{0} - {1} AT L {2} x W {3} x H {4}{5}",
				Y,
				"Skid(s)",
				epiText_Skid_ODD_L.Text,
				epiText_Skid_ODD_W.Text,
				epiText_Skid_ODD_H.Text,
				Environment.NewLine);
	
			edvShipHead.dataView[edvShipHead.Row]["Character10"]+= addfieldContents;
			SkidQty += Y;
		}
		
//	  SkidQty_before = edvShipHead.dataView[edvShipHead.Row]["Number02"];
        SkidQty_before = Convert.ToInt32((decimal)edvShipHead.dataView[edvShipHead.Row]["Number02"]);
		edvShipHead.dataView[edvShipHead.Row]["Number02"]= SkidQty + SkidQty_before ;

	}
}