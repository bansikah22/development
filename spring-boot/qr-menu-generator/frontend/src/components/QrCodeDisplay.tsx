import React from 'react';
import { Download, ExternalLink, QrCode } from 'lucide-react';
import type { QrCodeResponse } from '../types';

interface QrCodeDisplayProps {
  qrData: QrCodeResponse;
  restaurantName: string;
  onPreviewMenu: () => void;
}

const QrCodeDisplay: React.FC<QrCodeDisplayProps> = ({ qrData, restaurantName, onPreviewMenu }) => {
  const downloadQrCode = () => {
    const link = document.createElement('a');
    link.href = qrData.qrCode;
    link.download = `${restaurantName.replace(/[^a-z0-9]/gi, '_').toLowerCase()}_qr_code.png`;
    link.click();
  };

  return (
    <div className="max-w-md mx-auto">
      <div className="bg-white rounded-2xl shadow-xl border border-slate-200/60 overflow-hidden">
        {/* Header */}
        <div className="bg-gradient-to-r from-slate-50 to-slate-100 px-6 py-5 border-b border-slate-200/60">
          <div className="flex items-center justify-center mb-2">
            <div className="h-8 w-8 bg-gradient-to-br from-blue-500 to-purple-600 rounded-lg flex items-center justify-center mr-3">
              <QrCode className="w-4 h-4 text-white" />
            </div>
            <h2 className="text-xl font-bold text-slate-800">Your QR Menu is Ready!</h2>
          </div>
          <p className="text-slate-600 text-center text-sm">
            Customers can scan this code to instantly view your beautiful digital menu
          </p>
        </div>

        {/* QR Code */}
        <div className="p-8 bg-gradient-to-br from-slate-50/50 to-white">
          <div className="relative">
            <div className="absolute -inset-4 bg-gradient-to-r from-blue-500/20 to-purple-600/20 rounded-2xl blur-xl"></div>
            <div className="relative bg-white p-4 rounded-2xl border-2 border-slate-100 shadow-lg">
              <img 
                src={qrData.qrCode} 
                alt={`QR Code for ${restaurantName}`}
                className="w-full max-w-48 mx-auto rounded-xl"
              />
            </div>
          </div>
        </div>

        {/* Action Buttons */}
        <div className="px-6 pb-6 space-y-3">
          <button
            onClick={downloadQrCode}
            className="w-full bg-gradient-to-r from-blue-500 to-blue-600 text-white py-3 px-4 rounded-xl hover:from-blue-600 hover:to-blue-700 focus:outline-none focus:ring-2 focus:ring-blue-500 flex items-center justify-center font-medium transition-all duration-200 shadow-lg hover:shadow-xl"
          >
            <Download className="w-4 h-4 mr-2" />
            Download QR Code
          </button>

          <button
            onClick={onPreviewMenu}
            className="w-full bg-gradient-to-r from-emerald-500 to-emerald-600 text-white py-3 px-4 rounded-xl hover:from-emerald-600 hover:to-emerald-700 focus:outline-none focus:ring-2 focus:ring-emerald-500 flex items-center justify-center font-medium transition-all duration-200 shadow-lg hover:shadow-xl"
          >
            <ExternalLink className="w-4 h-4 mr-2" />
            Preview Customer Menu
          </button>
        </div>

        {/* URL Display */}
        <div className="px-6 pb-6">
          <div className="bg-slate-50 border border-slate-200/60 rounded-xl p-4">
            <p className="text-xs font-medium text-slate-500 mb-2 uppercase tracking-wide">
              Direct Menu Link:
            </p>
            <p className="font-mono text-xs text-slate-700 bg-white px-3 py-2 rounded-lg border break-all">
              {qrData.menuUrl}
            </p>
          </div>
        </div>
      </div>

      {/* Tips */}
      <div className="mt-6 bg-blue-50 border border-blue-200/60 rounded-xl p-4">
        <h3 className="font-semibold text-blue-800 mb-2 text-sm">💡 Pro Tips:</h3>
        <ul className="text-xs text-blue-700 space-y-1">
          <li>• Print the QR code and place it on tables</li>
          <li>• Add it to your website or social media</li>
          <li>• Update your menu anytime - QR code stays the same!</li>
        </ul>
      </div>
    </div>
  );
};

export default QrCodeDisplay;